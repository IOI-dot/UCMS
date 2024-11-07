#include "admin_student_management.h"
#include "ui_admin_student_management.h"

admin_student_management::admin_student_management(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_student_management)
{
    ui->setupUi(this);
}

admin_student_management::~admin_student_management()
{
    delete ui;
}
