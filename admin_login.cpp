// admin_login.cpp
#include "admin_login.h"
#include "ui_admin_login.h"
#include "admin_homepage.h"
#include <QMessageBox>
#include "admin.h"  // Include Admin class header for login verification
#include "file_manager.cpp"  // Include file manager to load data

Admin_Login::Admin_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin_Login)
    , admin("admin_username", "admin_password", "admin_email@example.com") // Initialize admin with credentials
{
    ui->setupUi(this);

    File_Manager fileManager;
    fileManager.loadAllData();
    QVector<Admin> admins = fileManager.loadAdminData();  // Load the admins from file
    Admin::loadAdminDataFromFile(admins);  // Store the data in Admin's static vector
}

Admin_Login::~Admin_Login()
{
    delete ui;
}

void Admin_Login::on_admin_login_pushButton_clicked()
{
    // Get username and password from the UI
    QString enteredUsername = ui->admin_username_lineEdit->text();
    QString enteredPassword = ui->admin_password_lineEdit->text();

    // Check login credentials
    if (admin.login(enteredUsername, enteredPassword)) {
        // Successful login
        QMessageBox::information(this, "Login Successful", "Welcome, Admin!");
        hide(); // Hide the login dialog

        // Store the logged-in admin in the static variable of Admin class
        Admin* loggedInAdmin = Admin::loggedInAdmin;

        // Show admin homepage
        admin_homepage *homepage = new admin_homepage(loggedInAdmin, this);
        homepage->show();
    } else {
        // Failed login
        QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again.");
    }
}
