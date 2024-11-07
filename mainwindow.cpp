#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student_login.h"
#include "admin_login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_student_pushButton_clicked()
{
    hide();
    Student_Login *student_login = new Student_Login;
    student_login->show();
}


void MainWindow::on_admin_pushButton_clicked()
{
    hide();
    Admin_Login *admin_login = new Admin_Login;
    admin_login->show();
}

