#include "student_registeration.h"
#include "ui_student_registeration.h"
#include "student_login.h"
#include "student.h"  // Include Student class to directly add a student
#include <QMessageBox>
Student_Registeration::Student_Registeration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Registeration)
{
    ui->setupUi(this);
}

Student_Registeration::~Student_Registeration()
{
    delete ui;
}

void Student_Registeration::on_sign_up_pushButton_clicked()
{
    // Get the data from the registration form
    QString username = ui->full_name_lineEdit->text();
    QString password = ui->password_regis_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    QString studentID = ui->UID_lineEdit->text();
    QString academicStatus = "Freshman";

    // Check if all fields are filled
    if (username.isEmpty() || password.isEmpty() || email.isEmpty() || studentID.isEmpty() || academicStatus.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // Create a new student object
    Student newStudent(username, password, email, studentID, academicStatus);

    // Add the student to the in-memory list
    Student::addStudent(newStudent);

    // Show a message confirming successful registration
    QMessageBox::information(this, "Registration Successful", "You have been successfully registered!");

    // Hide the registration dialog
    hide();

    // Show the login dialog
    Student_Login *studentLogin = new Student_Login();
    studentLogin->show();
}
