#ifndef STUDENT_ACADEMIC_PROFILE_H
#define STUDENT_ACADEMIC_PROFILE_H

#include <QDialog>
#include "student.h"

namespace Ui {
class student_academic_profile;
}

class student_academic_profile : public QDialog {
    Q_OBJECT

public:
    explicit student_academic_profile(QWidget *parent, Student& student);  // Pass by reference
    ~student_academic_profile();

    void displayStudentProfile();  // Display based on currentStudent reference

private:
    Ui::student_academic_profile* ui;
    Student& currentStudent;  // Reference to the actual student object
};

#endif // STUDENT_ACADEMIC_PROFILE_H
