#include "student_course_registration.h"
#include "ui_student_course_registration.h"
#include <QMessageBox>
#include <QDebug>
#include "student.h"

Student_Course_Registration::Student_Course_Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Course_Registration)
{
    ui->setupUi(this);

    // Populate the table with available courses
    populateCourses();

    // Populate the Registration list with the student's already registered courses
    populateRegistrationList();

    // Connect the "Register" button click signal to the corresponding slot
    connect(ui->PushADD, &QPushButton::clicked, this, &Student_Course_Registration::on_registerButton_clicked);

    // Connect the course selection change signal to the corresponding slot
    connect(ui->TABLECOURSES, &QTableWidget::itemSelectionChanged, this, &Student_Course_Registration::on_courseSelectionChanged);
}

Student_Course_Registration::~Student_Course_Registration()
{
    delete ui;
}

void Student_Course_Registration::populateCourses()
{
    // Get all available courses (assuming Course::getAllCourses() returns a QVector<Course>)
    QVector<Course> courses = Course::getAllCourses();

    ui->TABLECOURSES->setRowCount(courses.size());
    ui->TABLECOURSES->setColumnCount(5);  // Columns for ID, Name, Instructor, Credits, Prerequisites
    ui->TABLECOURSES->setHorizontalHeaderLabels(QStringList() << "Course ID" << "Course Name" << "Instructor" << "Credits" << "Prerequisites");

    for (int i = 0; i < courses.size(); ++i) {
        const Course &course = courses[i];

        // Populate the table with course details
        ui->TABLECOURSES->setItem(i, 0, new QTableWidgetItem(course.getCourseID()));
        ui->TABLECOURSES->setItem(i, 1, new QTableWidgetItem(course.getName()));
        ui->TABLECOURSES->setItem(i, 2, new QTableWidgetItem(course.getInstructor()));
        ui->TABLECOURSES->setItem(i, 3, new QTableWidgetItem(course.getSchedule()));
        ui->TABLECOURSES->setItem(i, 4, new QTableWidgetItem(course.getPrerequisites().join(", ")));
    }

    // Populate the ComboBox with all available courses
    ui->combo->clear();
    for (const Course &course : courses) {
        ui->combo->addItem(course.getName());  // Add course names to ComboBox
    }
}

void Student_Course_Registration::populateRegistrationList()
{
    // Get the logged-in student
    Student *currentStudent = Student::getLoggedInStudent();

    // Clear the list first
    ui->Registrationlist->clear();

    // Add each course the student is registered for to the list
    for (const QString &course : currentStudent->getRegisteredCourses()) {
        ui->Registrationlist->addItem(course);  // Add course name to ListWidget
    }
}

void Student_Course_Registration::on_registerButton_clicked()
{
    // Get the selected row in the table
    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();

    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a course to register.");
        return;
    }

    // Get course details from the selected row
    int row = selectedItems.first()->row();
    QString courseID = ui->TABLECOURSES->item(row, 0)->text();
    QString courseName = ui->TABLECOURSES->item(row, 1)->text();

    // Find the selected course in the available courses
    QVector<Course> courses = Course::getAllCourses();
    Course selectedCourse;

    for (const Course &course : courses) {
        if (course.getCourseID() == courseID) {
            selectedCourse = course;
            break;
        }
    }

    // Check if the student can register for the selected course
    if (canRegisterForCourse(selectedCourse)) {
        // Register the student for the course
        Student *currentStudent = Student::getLoggedInStudent();
        currentStudent->getRegisteredCourses().append(courseName);

        // Display confirmation message
        QMessageBox::information(this, "Registration Successful", "You have been successfully registered for the course: " + courseName);

        // Optionally, update the registration list (or refresh UI)
        populateRegistrationList();  // Refresh the list with the newly registered course
    } else {
        // Notify the student about unmet prerequisites
        QMessageBox::warning(this, "Prerequisite Error", "You do not meet the prerequisites for this course.");
    }
}

void Student_Course_Registration::on_courseSelectionChanged()
{
    // Update the prerequisite information when a course is selected
    updatePrerequisiteInfo();
}

void Student_Course_Registration::updatePrerequisiteInfo()
{
    // Get the selected course's prerequisites and display them in the label
    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();

    if (selectedItems.isEmpty()) {
        return;
    }

    int row = selectedItems.first()->row();
    QString prerequisites = ui->TABLECOURSES->item(row, 4)->text();

    // Update the prerequisite label text
    ui->prequesetes->setText("Prerequisites: " + prerequisites);
}

bool Student_Course_Registration::canRegisterForCourse(const Course& selectedCourse)
{
    // Get the logged-in student
    Student *currentStudent = Student::getLoggedInStudent();

    // Get the prerequisites for the course
    QVector<QString> prerequisites = selectedCourse.getPrerequisites();

    // Check if the prerequisites are explicitly set as "None"
    if (prerequisites.isEmpty() || prerequisites.contains("None")) {
        // No prerequisites or "None", the student can register
        return true;
    }

    // Check if the student has completed the prerequisites
    for (const QString &prerequisite : prerequisites) {
        if (!currentStudent->getRegisteredCourses().contains(prerequisite)) {
            // If any prerequisite is not met, return false
            qDebug() << "Student does not meet the prerequisite:" << prerequisite;
            return false;
        }
    }

    // All prerequisites are met
    return true;
}

