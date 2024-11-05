#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>

namespace Ui {
class Admin_Login;
}

class Admin_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Login(QWidget *parent = nullptr);
    ~Admin_Login();

private:
    Ui::Admin_Login *ui;
};

#endif // ADMIN_LOGIN_H
