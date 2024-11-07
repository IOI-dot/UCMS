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

private slots:
    void on_student_register_pushButton_clicked();

    void on_student_login_pushButton_clicked();

private:
    Ui::Student_Login *ui;
};

#endif // STUDENT_LOGIN_H
