#ifndef ADMIN_COURSE_MANAGEMENT_H
#define ADMIN_COURSE_MANAGEMENT_H

#include <QDialog>
#include <vector>
#include "course.h"
#include "file_manager.h"

namespace Ui {
class admin_course_management;
}

class admin_course_management : public QDialog {
    Q_OBJECT

public:
    explicit admin_course_management(QWidget *parent = nullptr);
    ~admin_course_management();

private slots:
    void on_ADD_clicked();
    void on_EDIT_clicked();
    void on_DelteBottun_clicked();

private:
    Ui::admin_course_management *ui;
    std::vector<Course> courses;
    QString filePath = "courses.txt";

    void loadCourses();
    void saveCourses();
    void refreshUI();
};

#endif // ADMIN_COURSE_MANAGEMENT_H
