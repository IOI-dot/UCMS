#include "admin_event_management.h"
#include "ui_admin_event_management.h"

admin_event_management::admin_event_management(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_event_management)
{
    ui->setupUi(this);
}

admin_event_management::~admin_event_management()
{
    delete ui;
}
