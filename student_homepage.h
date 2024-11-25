#ifndef STUDENT_HOMEPAGE_H
#define STUDENT_HOMEPAGE_H

#include <QDialog>
#include "student.h"  // Include the Student class to get access to the logged-in student's data

namespace Ui {
class student_homepage;
}

class student_homepage : public QDialog
{
    Q_OBJECT

public:
    explicit student_homepage(Student* student, QWidget *parent = nullptr);  // Pass the logged-in student here
    ~student_homepage();

private slots:
    void on_course_regis_pushButton_clicked();
    void on_event_regis_pushButton_clicked();
    void on_academic_profile_pushButton_clicked();
    void on_Exit_clicked();  // Slot for the exit button

private:
    Ui::student_homepage *ui;
    Student* loggedInStudent;  // Pointer to the logged-in student
};

#endif // STUDENT_HOMEPAGE_H
