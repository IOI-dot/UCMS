#ifndef STUDENT_COURSE_REGISTRATION_H
#define STUDENT_COURSE_REGISTRATION_H

#include <QDialog>

namespace Ui {
class Student_Course_Registration;
}

class Student_Course_Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Course_Registration(QWidget *parent = nullptr);
    ~Student_Course_Registration();

private:
    Ui::Student_Course_Registration *ui;
};

#endif // STUDENT_COURSE_REGISTRATION_H
