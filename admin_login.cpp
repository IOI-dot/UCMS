#include "admin_login.h"
#include "ui_admin_login.h"

Admin_Login::Admin_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin_Login)
{
    ui->setupUi(this);
}

Admin_Login::~Admin_Login()
{
    delete ui;
}
