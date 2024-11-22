#ifndef STUDENT_ACADEMIC_PROFILE_H
#define STUDENT_ACADEMIC_PROFILE_H

#include <QDialog>
#include "student.h" // Include the Student class

namespace Ui {
class student_academic_profile;
}
// student_academic_profile.h
class student_academic_profile : public QDialog
{
    Q_OBJECT

public:
    explicit student_academic_profile(QWidget *parent = nullptr, const Student& student = Student());
    ~student_academic_profile();

    void displayStudentProfile(const Student& student);  // Function to display student data

private:
    Ui::student_academic_profile *ui;
    const Student& currentStudent;  // Reference to the student

};


#endif // STUDENT_ACADEMIC_PROFILE_H
