#include "student_registeration.h"
#include "ui_student_registeration.h"
#include "student_login.h"

Student_Registeration::Student_Registeration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Registeration)
{
    ui->setupUi(this);
}

Student_Registeration::~Student_Registeration()
{
    delete ui;
}

void Student_Registeration::on_sign_up_pushButton_clicked()
{
    hide();
    Student_Login *student_login = new Student_Login;
    student_login->show();
}


