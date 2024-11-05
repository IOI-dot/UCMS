#ifndef STUDENT_LOGIN_H
#define STUDENT_LOGIN_H

#include <QDialog>

namespace Ui {
class Student_Login;
}

class Student_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Login(QWidget *parent = nullptr);
    ~Student_Login();

private:
    Ui::Student_Login *ui;
};

#endif // STUDENT_LOGIN_H
