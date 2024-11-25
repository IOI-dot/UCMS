#include "admin_student_management.h"
#include "ui_admin_student_management.h"
#include <QMessageBox>
#include <QDebug>
#include "admin.h"
#include "student_academic_profile.h"
#include "admin_homepage.h"
admin_student_management::admin_student_management(Admin* admin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_student_management),
    currentAdmin(admin)  // Store the passed Admin pointer
{
    ui->setupUi(this);

    connect(ui->VIEW, &QPushButton::clicked, this, &admin_student_management::onViewStudentClicked);
    connect(ui->ADD, &QPushButton::clicked, this, &admin_student_management::onAddStudentClicked);
    connect(ui->DELETE, &QPushButton::clicked, this, &admin_student_management::onDeleteStudentClicked);
    // Connect the Back button to the slot
    connect(ui->Back, &QPushButton::clicked, this, &admin_student_management::on_Back_clicked);
}

admin_student_management::~admin_student_management()
{
    delete ui;
}

void admin_student_management::onViewStudentClicked() {
    QString studentID = ui->StudentID->text().trimmed();  // Ensure to trim the input

    QVector<Student>& allStudents = currentAdmin->viewStudents();  // Get reference to student list

    for (Student& student : allStudents) {
        if (student.getStudentID() == studentID) {
            // Pass the student by reference to the profile dialog
            student_academic_profile *profileDialog = new student_academic_profile(this, student);
            profileDialog->show();
            return;
        }
    }

    QMessageBox::warning(this, "Student Not Found", "No student found with this ID.");
}

void admin_student_management::onAddStudentClicked() {
    QString studentID = ui->StudentID->text().trimmed();
    QString courseCRN = ui->COURSE_CRN->text().trimmed();

    if (studentID.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter a valid Student ID.");
        return;
    }

    if (courseCRN.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter a valid CRN.");
        return;
    }

    // Check if the course exists in the course list
    bool courseExists = false;
    for (const Course& course : Course::courseList) {
        if (course.getCourseID() == courseCRN) {
            courseExists = true;
            break;  // Course found, no need to continue searching
        }
    }

    if (!courseExists) {
        QMessageBox::warning(this, "Course Not Found", "The course with the given CRN does not exist.");
        return;  // Exit the function if course does not exist
    }

    // Get the list of students
    QVector<Student>& allStudents = currentAdmin->viewStudents();  // Get reference to student list
    for (Student& student : allStudents) {  // Use a reference to modify the original student
        if (student.getStudentID() == studentID) {
            // Add course to the student's registration if not already registered
            QVector<QString> registeredCourses = student.getRegisteredCourses();
            if (!registeredCourses.contains(courseCRN)) {
                registeredCourses.append(courseCRN);
                student.setRegisteredCourses(registeredCourses);  // Update the student's courses list
                QMessageBox::information(this, "Success", "Course added to the student.");
            } else {
                QMessageBox::information(this, "Duplicate", "Student is already registered for this course.");
            }

            // Refresh the profile and pass the student by reference
            student_academic_profile* profileDialog = new student_academic_profile(this, student);
            profileDialog->show();
            return;
        }
    }

    QMessageBox::warning(this, "Student Not Found", "No student found with this ID.");
}

void admin_student_management::onDeleteStudentClicked() {
    QString studentID = ui->StudentID->text().trimmed();
    QString courseCRN = ui->COURSE_CRN->text().trimmed();

    if (studentID.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter a valid Student ID.");
        return;
    }

    if (courseCRN.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter a valid CRN.");
        return;
    }

    // Get the list of students from the admin
    QVector<Student>& allStudents = currentAdmin->viewStudents();  // Get reference to student list
    for (Student& student : allStudents) {  // Use reference to modify the original student
        if (student.getStudentID() == studentID) {
            // Remove course from the student's registration
            QVector<QString> registeredCourses = student.getRegisteredCourses();
            if (registeredCourses.contains(courseCRN)) {
                registeredCourses.removeAll(courseCRN);
                student.setRegisteredCourses(registeredCourses);  // Update the student's courses list
                QMessageBox::information(this, "Success", "Course removed from the student's registration.");

            } else {
                QMessageBox::information(this, "Not Found", "The student is not registered for this course.");
            }

            // Refresh the profile and pass the student by reference
            student_academic_profile* profileDialog = new student_academic_profile(this, student);
            profileDialog->show();
            return;
        }
    }

    QMessageBox::warning(this, "Student Not Found", "No student found with this ID.");
}
// Slot for Back button click
void admin_student_management::on_Back_clicked() {
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}
