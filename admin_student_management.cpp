#include "admin_student_management.h"
#include "ui_admin_student_management.h"
#include <QMessageBox>
#include <QDebug>
#include "admin.h"
#include "student_academic_profile.h"

// Constructor to accept the Admin object and store it
admin_student_management::admin_student_management(Admin* admin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_student_management),
    currentAdmin(admin)  // Store the passed Admin pointer
{
    ui->setupUi(this);

    connect(ui->VIEW, &QPushButton::clicked, this, &admin_student_management::onViewStudentClicked);
    connect(ui->ADD, &QPushButton::clicked, this, &admin_student_management::onAddStudentClicked);
    connect(ui->DELETE, &QPushButton::clicked, this, &admin_student_management::onDeleteStudentClicked);
}

admin_student_management::~admin_student_management()
{
    delete ui;
}

// View student profile based on student ID
void admin_student_management::onViewStudentClicked() {
    QString studentID = ui->StudentID->text();

    // Check if the student exists in the currentAdmin's list
    QVector<Student> allStudents = currentAdmin->viewStudents();  // Use the Admin object's viewStudents function

    for (const Student& student : allStudents) {
        if (student.getStudentID() == studentID) {
            // Show student profile
            student_academic_profile *profileDialog = new student_academic_profile;
            profileDialog->displayStudentProfile(student);
            profileDialog->show();
            return;
        }
    }

    QMessageBox::warning(this, "Student Not Found", "No student found with this ID.");
}

// Add student to a course (by adding CRN)
void admin_student_management::onAddStudentClicked() {
    QString studentID = ui->StudentID->text();
    QString courseCRN = ui->COURSE_CRN->text();

    // Check if the student exists in the currentAdmin's list
    QVector<Student> allStudents = currentAdmin->viewStudents();  // Use the Admin object's viewStudents function

    for (Student& student : allStudents) {
        if (student.getStudentID() == studentID) {
            // Add course to the student's registration
            student.getRegisteredCourses().append(courseCRN);
            QMessageBox::information(this, "Success", "Course added to student.");
            return;
        }
    }

    QMessageBox::warning(this, "Student Not Found", "No student found with this ID.");
}

void admin_student_management::onDeleteStudentClicked() {
    QString studentID = ui->StudentID->text();

    // Try to cast the studentID to an integer
    bool ok;
    int studentIDInt = studentID.toInt(&ok);  // Convert to int, &ok will indicate success or failure

    if (!ok) {
        QMessageBox::warning(this, "Invalid ID", "Student ID must be a valid number.");
        return;  // Exit the function if the conversion failed
    }

    // Now use the integer value for removing the student
    if (currentAdmin->removeStudent(studentIDInt)) {
        QMessageBox::information(this, "Success", "Student deleted.");
    } else {
        QMessageBox::warning(this, "Error", "Student not found.");
    }
}
