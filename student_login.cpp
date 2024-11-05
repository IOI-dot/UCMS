#include "student_login.h"
#include "ui_student_login.h"

Student_Login::Student_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Login)
{
    ui->setupUi(this);
}

Student_Login::~Student_Login()
{
    delete ui;
}
