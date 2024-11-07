#include "student_academic_profile.h"
#include "ui_student_academic_profile.h"

student_academic_profile::student_academic_profile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::student_academic_profile)
{
    ui->setupUi(this);
}

student_academic_profile::~student_academic_profile()
{
    delete ui;
}
