#include "admin_homepage.h"
#include "ui_admin_homepage.h"
#include "admin_course_management.h"
#include "admin_student_management.h"
#include "admin_event_management.h"

admin_homepage::admin_homepage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_homepage)
{
    ui->setupUi(this);
}

admin_homepage::~admin_homepage()
{
    delete ui;
}

void admin_homepage::on_pushButton_clicked()
{
    hide();
    admin_course_management *Admin_course_management = new admin_course_management;
    Admin_course_management->show();
}


void admin_homepage::on_pushButton_2_clicked()
{
    hide();
    admin_student_management *Admin_student_management = new admin_student_management;
    Admin_student_management->show();
}


void admin_homepage::on_pushButton_3_clicked()
{
    hide();
    admin_event_management *Admin_event_management = new admin_event_management;
    Admin_event_management->show();
}

