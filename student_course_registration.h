#ifndef STUDENT_COURSE_REGISTRATION_H
#define STUDENT_COURSE_REGISTRATION_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include "course.h"
#include "student.h"

namespace Ui {
class Student_Course_Registration;
}

class Student_Course_Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Course_Registration(QWidget *parent = nullptr, Student* student = nullptr);  // Pass Student pointer
    ~Student_Course_Registration();

private slots:
    void on_register_2_clicked();  // Slot for Register button click
    void on_courseSelectionChanged();  // Slot for course selection change
    void on_Back_clicked();  // Slot for Back button
private:
    Ui::Student_Course_Registration *ui;
    Student* currentStudent;  // Store the logged-in student
    void populateCourses();  // Populate course table with available courses
    void populateRegistrationList();  // Populate registration list with the student's registered courses
    void updatePrerequisiteInfo();  // Update the prerequisite info label
    bool canRegisterForCourse(const Course& selectedCourse);  // Check if prerequisites are met
};

#endif // STUDENT_COURSE_REGISTRATION_H

