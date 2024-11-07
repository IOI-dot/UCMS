#include "admin_course_management.h"
#include "ui_admin_course_management.h"

admin_course_management::admin_course_management(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_course_management)
{
    ui->setupUi(this);
}

admin_course_management::~admin_course_management()
{
    delete ui;
}
