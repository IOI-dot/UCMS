#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Admin_Login;
}

class Admin_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Login(QWidget *parent = nullptr);
    ~Admin_Login();

private slots:
    void on_admin_login_pushButton_clicked();

private:
    Ui::Admin_Login *ui;
    Admin admin; // Instance of Admin to handle login
};

#endif // ADMIN_LOGIN_H
