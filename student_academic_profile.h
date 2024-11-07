#ifndef STUDENT_ACADEMIC_PROFILE_H
#define STUDENT_ACADEMIC_PROFILE_H

#include <QDialog>

namespace Ui {
class student_academic_profile;
}

class student_academic_profile : public QDialog
{
    Q_OBJECT

public:
    explicit student_academic_profile(QWidget *parent = nullptr);
    ~student_academic_profile();

private:
    Ui::student_academic_profile *ui;
};

#endif // STUDENT_ACADEMIC_PROFILE_H
