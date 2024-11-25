#include "student_academic_profile.h"
#include "ui_student_academic_profile.h"
#include "student.h"
#include "course.h"  // Include the header file where Course is defined
#include "student_homepage.h"
student_academic_profile::student_academic_profile(QWidget *parent, Student& student)
    : QDialog(parent),
    ui(new Ui::student_academic_profile),
    currentStudent(student)  // Store reference to the actual student
{
    ui->setupUi(this);
    displayStudentProfile();  // Populate UI with current student data
    connect(ui->Back, &QPushButton::clicked, this, &student_academic_profile::on_Back_clicked);
}


student_academic_profile::~student_academic_profile() {
    delete ui;
}

void student_academic_profile::displayStudentProfile() {
    // Set the student's name
    ui->namelabel->setText(currentStudent.getUsername());

    // Set the student's ID
    ui->idlabel->setText(currentStudent.getStudentID());

    // Set the student's academic status
    ui->aslabel->setText(currentStudent.getAcademicStatus());

    // Get the list of courses registered by the student
    QVector<QString> registeredCourses = currentStudent.getRegisteredCourses();
    qDebug() << "Registered Courses:";
    for (const QString& course : registeredCourses) {
        qDebug() << course;
    }
    // Vector to hold the course names or other information to be displayed
    QStringList courseDetails;

    // Loop through the registered courses and fetch details for each
    for (const QString& courseName : registeredCourses) {
        bool found = false;

        // Only search through courses (not events)
        for (const Course& course : Course::getAllCourses()) {
            if (course.getName() == courseName) {  // Match course name
                // Add the course details to the list (e.g., name and instructor)
                courseDetails.append(course.getName() + " - " + course.getInstructor());
                found = true;
                break;
            }
        }

        // If course is not found in the course list, add a "not found" message
        if (!found) {
            courseDetails.append(courseName);
        }
    }

    // Check if courses are registered
    QString courseText;
    if (courseDetails.isEmpty()) {
        courseText = "No courses registered."; // In case the student has no courses
    } else {
        courseText = "Courses Registered: \n" + courseDetails.join("\n");  // Join courses with newline
    }

    // Set the courses label (this will display the courses in the UI)
    ui->courselabel->setText(courseText);
}


// Slot to handle the Back button click
void student_academic_profile::on_Back_clicked()
{
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}
