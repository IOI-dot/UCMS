#include "student_login.h"
#include "ui_student_login.h"
#include "student_registeration.h"
#include "student_homepage.h"

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

void Student_Login::on_student_register_pushButton_clicked()
{
    hide();
    Student_Registeration *student_registeration = new Student_Registeration;
    student_registeration->show();
}


void Student_Login::on_student_login_pushButton_clicked()
{
    hide();
    student_homepage *Student_homepage = new student_homepage;
    Student_homepage->show();
}

