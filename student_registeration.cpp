#include "student_registeration.h"
#include "ui_student_registeration.h"

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
