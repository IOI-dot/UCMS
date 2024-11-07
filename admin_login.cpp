#include "admin_login.h"
#include "ui_admin_login.h"
#include "admin_homepage.h"

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

void Admin_Login::on_admin_login_pushButton_clicked()
{
    hide();
    admin_homepage *Admin_homepage = new admin_homepage;
    Admin_homepage->show();
}

