#ifndef ADMIN_HOMEPAGE_H
#define ADMIN_HOMEPAGE_H

#include <QDialog>  // QDialog is used as the base class for dialog-based UI
#include "admin.h"  // Include the Admin class for logged-in admin management
#include "file_manager.h"
namespace Ui {
class admin_homepage;  // Forward declaration of the UI class for admin_homepage
}

class admin_homepage : public QDialog  // QDialog is the base class
{
    Q_OBJECT  // This macro is essential for Qt's signal and slot mechanism

public:
    // Constructor to initialize with logged-in admin object
    explicit admin_homepage(Admin* loggedInAdmin, QWidget *parent = nullptr);

    // Destructor to clean up the UI
    ~admin_homepage();

private slots:
    // You can later define these slots to handle button actions
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_Exit_clicked();         // EXIT Button
private:
    // Member variables
    Admin* currentAdmin;  // Store the logged-in admin object
    Ui::admin_homepage *ui;  // Pointer to the auto-generated UI class (from Qt Designer)
};

#endif // ADMIN_HOMEPAGE_H
