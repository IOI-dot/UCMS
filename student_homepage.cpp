#include "student_homepage.h"
#include "ui_student_homepage.h"
#include "student_course_registration.h"
#include "student_event_registration.h"
#include "student_academic_profile.h"
#include <QMessageBox>  // Include for QMessageBox
#include "file_manager.h"
extern Student* getCurrentStudent();  // Declare the external getCurrentStudent function

// Constructor now accepts a logged-in student pointer
student_homepage::student_homepage(Student* student, QWidget *parent)
    : QDialog(parent), ui(new Ui::student_homepage), loggedInStudent(student)  // Store the student pointer
{
    ui->setupUi(this);

    // Now the loggedInStudent is available for use
    if (loggedInStudent) {
        // You can show the student's information on the UI if needed, for example:
        qDebug() << "Logged-in student: " << loggedInStudent->getUsername();
    }

    // Connect the Exit button to the appropriate slot
    connect(ui->Exit, &QPushButton::clicked, this, &student_homepage::on_Exit_clicked);
}

student_homepage::~student_homepage()
{
    delete ui;
}

void student_homepage::on_course_regis_pushButton_clicked()
{
    hide();
    Student_Course_Registration *student_course_registration = new Student_Course_Registration(this, loggedInStudent);
    student_course_registration->show();
}


void student_homepage::on_event_regis_pushButton_clicked()
{
    // Hide the current homepage dialog
    hide();

    // Create a new instance of the student_event_registration dialog, passing the logged-in student
    student_event_registration *student_event_registration_dialog = new student_event_registration(loggedInStudent, this);

    // Show the student event registration dialog
    student_event_registration_dialog->show();
}


// In student_homepage.cpp

void student_homepage::on_academic_profile_pushButton_clicked()
{
    // Get the logged-in student
    Student* loggedInStudent = Student::getLoggedInStudent();

    // Ensure a student is logged in before proceeding
    if (!loggedInStudent) {
        QMessageBox::critical(this, "Error", "No student is currently logged in.");
        qDebug() << "No student is logged in!";
        return;  // Exit function to avoid crashes
    }

    // Validate that the logged-in student has a valid ID
    if (loggedInStudent->getStudentID().isEmpty()) {
        QMessageBox::critical(this, "Error", "The logged-in student data is invalid.");
        qDebug() << "Invalid student data!";
        return;
    }

    // Hide the current homepage
    hide();

    // Pass the logged-in student to the academic profile dialog
    student_academic_profile *profileDialog = new student_academic_profile(this, *loggedInStudent);  // Pass as reference
    profileDialog->show();  // Show the academic profile dialog
}
void student_homepage::on_Exit_clicked()
{
    // Save the student data before exiting
    if (loggedInStudent) {
        // Save all data before exiting
        qDebug() << "Saving all changes before exiting...";
        File_Manager fileManager;
        fileManager.saveStudentData(Student::studentList);  // Save the changes in the student data to the file
      qDebug() << "All changes saved successfully.";
    }
    // Close the current window
    this->close();
}
