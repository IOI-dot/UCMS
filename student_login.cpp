#include "student_login.h"
#include "student_registeration.h"
#include "ui_student_login.h"
#include "student_homepage.h"
#include <QMessageBox>
#include "student.h"  // Include Student class header for login verification
#include "file_manager.h"  // Include file manager to load student data

int i = 0;

Student_Login::Student_Login(QWidget *parent)
    : QDialog(parent), ui(new Ui::Student_Login)
{
    ui->setupUi(this);

    if (i == 0) {
        // Load student data from file into static list
        File_Manager fileManager;
        fileManager.loadAllData();
        QVector<Student> students = fileManager.loadStudentData();  // Load the students from file
        Student::studentList = students;  // Store the data in Student's static vector
        i++;
    }
}

Student_Login::~Student_Login()
{
    delete ui;
}

void Student_Login::on_student_login_pushButton_clicked()
{
    // Get input from the line edits
    QString enteredUsername = ui->student_username_login_lineEdit->text();
    QString enteredStudentID = ui->student_id_login_lineEdit->text();

    // Check if fields are empty
    if (enteredUsername.isEmpty() || enteredStudentID.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Both Username and Student ID fields must be filled.");
        return;
    }

    // Use the Student::login method to check the login credentials
    if (Student::verifyLogin(enteredUsername, enteredStudentID)) {
        // If login is successful, get the logged-in student
        Student* loggedInStudent = Student::getLoggedInStudent();

        if (loggedInStudent) {
            // Show success message and proceed to the homepage
            QMessageBox::information(this, "Login Successful", "Welcome, " + loggedInStudent->getUsername() + "!");
            hide();  // Hide the login dialog

            // Open the student homepage
            student_homepage *homepage = new student_homepage;
            homepage->show();
        } else {
            QMessageBox::critical(this, "Error", "Login verification succeeded, but student could not be retrieved.");
        }
    } else {
        // If login failed
        QMessageBox::warning(this, "Login Failed", "Invalid username or student ID. Please try again.");
    }
}

void Student_Login::on_student_register_pushButton_clicked()
{
    // Hide the login dialog
    this->hide();

    // Create and show the registration dialog
    Student_Registeration *registerDialog = new Student_Registeration();
    registerDialog->show();
}
