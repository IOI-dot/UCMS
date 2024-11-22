#include "student_login.h"
#include "student_registeration.h"
#include "ui_student_login.h"
#include "student_homepage.h"
#include <QMessageBox>
#include "student.h"  // Include Student class header for login verification
#include "file_manager.h"  // Include file manager to load student data

Student_Login::Student_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Login)
{
    ui->setupUi(this);

    // Instantiate File_Manager to load student data from file
    File_Manager fileManager;
    QVector<Student> students = fileManager.loadStudentData();  // Load the students from file
    Student::studentList = students;  // Store the data in Student's static vector
}

Student_Login::~Student_Login()
{
    delete ui;
}

void Student_Login::on_student_login_pushButton_clicked()
{
    // Get username and student ID from the UI
    QString enteredUsername = ui->student_username_login_lineEdit->text();
    QString enteredStudentID = ui->student_id_login_lineEdit->text();  // Assuming student ID is used for login

    // Attempt to verify the student's login credentials
    if (Student::verifyLogin(enteredUsername, enteredStudentID)) {
        // Successful login
        QMessageBox::information(this, "Login Successful", "Welcome, Student!");
        hide(); // Hide the login dialog

        // Show student homepage
        student_homepage *Student_homepage = new student_homepage;
        Student_homepage->show();
    } else {
        // Failed login
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
