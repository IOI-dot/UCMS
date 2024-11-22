#include "admin_homepage.h"
#include "ui_admin_homepage.h"
#include "admin_course_management.h"
#include "admin_student_management.h"
#include "admin_event_management.h"

// Constructor: Set up the UI and store the logged-in admin
admin_homepage::admin_homepage(Admin* loggedInAdmin, QWidget *parent) :
    QDialog(parent),              // Initialize QDialog first
    currentAdmin(loggedInAdmin),  // Initialize currentAdmin with the passed-in Admin pointer
    ui(new Ui::admin_homepage)    // Initialize UI last (after currentAdmin)
{
    if (currentAdmin == nullptr) {
        qWarning() << "Received null Admin pointer!";
        return; // Return early or handle the case where currentAdmin is nullptr
    }
    ui->setupUi(this);  // Setup the UI
qDebug() << "Logged-in Admin Username: " << currentAdmin->getUsername();
    // Example usage: Display the admin's username in a label
    ui->label_welcome->setText("Welcome, " + currentAdmin->getUsername());
}

admin_homepage::~admin_homepage()
{
    delete ui;  // Cleanup the UI when the dialog is destroyed
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

    // Pass the currentAdmin pointer to the admin_student_management constructor
    admin_student_management *Admin_student_management = new admin_student_management(currentAdmin);

    Admin_student_management->show();
}



void admin_homepage::on_pushButton_3_clicked()
{
    hide();
    admin_event_management *Admin_event_management = new admin_event_management;
    Admin_event_management->show();
}

