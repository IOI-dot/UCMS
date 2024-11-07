#include "student_event_registration.h"
#include "ui_student_event_registration.h"

student_event_registration::student_event_registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::student_event_registration)
{
    ui->setupUi(this);
}

student_event_registration::~student_event_registration()
{
    delete ui;
}
