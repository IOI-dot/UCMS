#include "student_login.h"
#include "ui_student_login.h"
#include "student_registeration.h"
#include "student_homepage.h"
#include "student.h"
#include <QMessageBox>  // Include for QMessageBox

// Static variable to hold the currently logged-in student
Student* currentStudent = nullptr;

Student_Login::Student_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Login)
{
    ui->setupUi(this);
}

Student_Login::~Student_Login()
{
    delete ui;
}

void Student_Login::on_student_register_pushButton_clicked()
{
    hide();
    Student_Registeration *student_registeration = new Student_Registeration;
    student_registeration->show();
}

void Student_Login::on_student_login_pushButton_clicked()
{
    // Get username and password input from the UI (assume there are QLineEdits for this)
    QString username = ui->student_username_login_lineEdit->text();
    QString id = ui->student_id_login_lineEdit->text();

    // Attempt to find the student by username and password
    Student* student = findStudentByUsernameAndPassword(username, id);

    if (student != nullptr) {
        // Set the current student if login is successful
        setCurrentStudent(student);

        // Hide the login window and show the student homepage
        hide();
        student_homepage *Student_homepage = new student_homepage;
        Student_homepage->show();
    } else {
        // Display an error message if login fails
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

// Simulated function to find a student (you should replace this with your actual logic)
Student* Student_Login::findStudentByUsernameAndPassword(const QString& username, const QString& password)
{
    // Replace with your actual student retrieval logic (e.g., from a database or list)
    // For now, creating a dummy student object (you can improve this logic)
    if (username == "test" && password == "password") {
        return new Student("test", "password", "test@example.com", "12345");  // Create Student with 4 arguments
    }
    return nullptr;
}

// Getter for the current student
Student* getCurrentStudent() {
    return currentStudent;
}

// Setter for the current student
void setCurrentStudent(Student* student) {
    currentStudent = student;
}
