#ifndef ADMIN_STUDENT_MANAGEMENT_H
#define ADMIN_STUDENT_MANAGEMENT_H

#include <QDialog>
#include "admin.h"  // Include Admin class
#include "student_academic_profile.h"  // Include student profile dialog
namespace Ui {
class admin_student_management;
}

class admin_student_management : public QDialog
{
    Q_OBJECT

public:
    explicit admin_student_management(Admin* admin, QWidget *parent = nullptr);  // Accept Admin pointer
    ~admin_student_management();

private slots:
    void onViewStudentClicked();
    void onAddStudentClicked();
    void onDeleteStudentClicked();

private:
    Admin* currentAdmin;  // Member variable to store the logged-in admin
    Ui::admin_student_management *ui;
};

#endif // ADMIN_STUDENT_MANAGEMENT_H
