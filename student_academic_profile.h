#ifndef STUDENT_ACADEMIC_PROFILE_H
#define STUDENT_ACADEMIC_PROFILE_H
#include "student.h"
#include <QDialog>

namespace Ui {
class student_academic_profile;
}

class student_academic_profile : public QDialog
{
    Q_OBJECT

public:

    explicit student_academic_profile(Student* student, QWidget *parent = nullptr);
    ~student_academic_profile();

private:
    Ui::student_academic_profile *ui;
     Student* student;
    void populateStudentProfile();
};

#endif // STUDENT_ACADEMIC_PROFILE_H
