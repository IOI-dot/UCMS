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
    explicit Student_Course_Registration(QWidget *parent = nullptr);
    ~Student_Course_Registration();

private slots:
    void on_registerButton_clicked();  // Slot for Register button click
    void on_courseSelectionChanged();  // Slot for course selection change

private:
    Ui::Student_Course_Registration *ui;
    void populateCourses();  // Populate course table with available courses
    void populateRegistrationList();  // Populate registration list with the student's registered courses
    void updatePrerequisiteInfo();  // Update the prerequisite info label
    bool canRegisterForCourse(const Course& selectedCourse);  // Check if prerequisites are met
};

#endif // STUDENT_COURSE_REGISTRATION_H
