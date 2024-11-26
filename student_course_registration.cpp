#include "student_course_registration.h"
#include "ui_student_course_registration.h"
#include <QMessageBox>
#include <QDebug>
#include "student.h"
#include "student_homepage.h"
    static int callCount = 0;
Student_Course_Registration::Student_Course_Registration(QWidget *parent, Student* student) :
    QDialog(parent),
    ui(new Ui::Student_Course_Registration),
    currentStudent(student)  // Store the pointer to the logged-in student
{
    ui->setupUi(this);
    // Initialize or populate as required
    populateCourses();
    populateRegistrationList();

    connect(ui->register_2, &QPushButton::clicked, this, &Student_Course_Registration::on_register_2_clicked);
    connect(ui->TABLECOURSES, &QTableWidget::itemSelectionChanged, this, &Student_Course_Registration::on_courseSelectionChanged);
    connect(ui->Back, &QPushButton::clicked, this, &Student_Course_Registration::on_Back_clicked);
}

Student_Course_Registration::~Student_Course_Registration()
{
    delete ui;
}

void Student_Course_Registration::populateCourses()
{
    QVector<Course> courses = Course::getAllCourses();

    ui->TABLECOURSES->setRowCount(courses.size());
    ui->TABLECOURSES->setColumnCount(6);  // Now we have one more column for Completed Prerequisites
    ui->TABLECOURSES->setHorizontalHeaderLabels(QStringList() << "Course ID" << "Course Name" << "Instructor" << "Credits" << "Prerequisites" << "Completed Prerequisites");
    QVector<QString> globalCompletedPrerequisites = Student::getCurrentStudentPrerequisites(); // Use static data
    for (int i = 0; i < courses.size(); ++i) {
        const Course &course = courses[i];

        // Populate the table with course details
        ui->TABLECOURSES->setItem(i, 0, new QTableWidgetItem(course.getCourseID()));
        ui->TABLECOURSES->setItem(i, 1, new QTableWidgetItem(course.getName()));
        ui->TABLECOURSES->setItem(i, 2, new QTableWidgetItem(course.getInstructor()));
        ui->TABLECOURSES->setItem(i, 3, new QTableWidgetItem(course.getSchedule()));
        ui->TABLECOURSES->setItem(i, 4, new QTableWidgetItem(course.getPrerequisites().join(", ")));

        // Check completed prerequisites
        QStringList completedList;
        for (const QString& prereq : course.getPrerequisites()) {
            if (globalCompletedPrerequisites.contains(prereq)) {
                completedList.append(prereq);
            }
        }
        ui->TABLECOURSES->setItem(i, 5, new QTableWidgetItem(completedList.join(", ")));
    }
}


void Student_Course_Registration::populateRegistrationList()
{
    ui->Registrationlist->clear();  // Clear the existing list


    if (currentStudent) {
        qDebug() << "Populating Registration List with:" << currentStudent->getRegisteredCourses();

        for (const QString &course : currentStudent->getRegisteredCourses()) {
            ui->Registrationlist->addItem(course);
        }
    } else {
        qDebug() << "currentStudent is null in populateRegistrationList.";
    }
}

void Student_Course_Registration::on_register_2_clicked()
{
    ++callCount;
    if (callCount == 2) {
        callCount = 0;
        return;
    }

    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a course to register.");
        return;
    }

    int row = selectedItems.first()->row();
    QString courseID = ui->TABLECOURSES->item(row, 0)->text();
    QString courseName = ui->TABLECOURSES->item(row, 1)->text();

    QVector<Course> courses = Course::getAllCourses();
    Course selectedCourse;
    bool courseFound = false;

    for (const Course &course : courses) {
        if (course.getCourseID() == courseID) {
            selectedCourse = course;
            courseFound = true;
            break;
        }
    }

    if (!courseFound) {
        QMessageBox::critical(this, "Error", "Selected course could not be found.");
        return;
    }

    if (!canRegisterForCourse(selectedCourse)) {
        QMessageBox::warning(this, "Prerequisite Error",
                             "You do not meet the prerequisites for this course: " +
                                 selectedCourse.getPrerequisites().join(", "));
        return;
    }

    QVector<QString> registeredCourses = Student::getLoggedInStudent()->getRegisteredCourses();

    if (registeredCourses.contains(courseName)) {
        QMessageBox::information(this, "Already Registered", "You are already registered for this course.");
        return;
    }

    registeredCourses.append(courseName);
    Student::getLoggedInStudent()->setRegisteredCourses(registeredCourses);

    QMessageBox::information(this, "Registration Successful",
                             "You have been successfully registered for the course: " + courseName);

    populateRegistrationList();
}


void Student_Course_Registration::on_courseSelectionChanged()
{
    // Update the prerequisite information when a course is selected
    updatePrerequisiteInfo();
}

void Student_Course_Registration::updatePrerequisiteInfo()
{
    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();

    if (selectedItems.isEmpty()) {
        return;
    }

    int row = selectedItems.first()->row();
    QString prerequisites = ui->TABLECOURSES->item(row, 4)->text();

    ui->prequesetes->setText("Prerequisites: " + prerequisites);
}

bool Student_Course_Registration::canRegisterForCourse(const Course& selectedCourse)
{
    QVector<QString> prerequisites = selectedCourse.getPrerequisites();

    if (prerequisites.isEmpty() || prerequisites.contains("None")) {
        return true;
    }

    QVector<QString> completedPrerequisites = Student::currentStudentPrerequisites;
    qDebug() << "Current Student Prerequisites (Static):" << Student::currentStudentPrerequisites;

    for (const QString &prerequisite : prerequisites) {
        if (!completedPrerequisites.contains(prerequisite)) {
            return false;
        }
    }

    return true;
}



void Student_Course_Registration::on_Back_clicked()
{
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}
