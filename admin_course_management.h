#ifndef ADMIN_COURSE_MANAGEMENT_H
#define ADMIN_COURSE_MANAGEMENT_H

#include <QDialog>
#include <vector>
#include "course.h"
#include "file_manager.h"
#include "admin_homepage.h"  // Include the header for the admin homepage (adjust this if the class is named differently)

namespace Ui {
class admin_course_management;
}

class admin_course_management : public QDialog {
    Q_OBJECT

public:
    explicit admin_course_management(Admin* admin, QWidget *parent);
    ~admin_course_management();

private slots:
    void on_ADD_clicked();
    void on_EDIT_clicked();
    void on_DelteBottun_clicked();
    void on_BackToHome_clicked();  // Slot to handle going back to the homepage

private:
    Ui::admin_course_management *ui;
    std::vector<Course> courses;
    QString filePath = "courses.txt";
    Admin* currentAdmin;  // Declare the currentAdmin member variable
    void loadCourses();
    void saveCourses();
    void refreshUI();
    void goToAdminHomepage();  // Function to navigate back to the admin homepage
};

#endif // ADMIN_COURSE_MANAGEMENT_H
