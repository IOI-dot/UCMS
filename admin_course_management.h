#ifndef ADMIN_COURSE_MANAGEMENT_H
#define ADMIN_COURSE_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class admin_course_management;
}

class admin_course_management : public QDialog
{
    Q_OBJECT

public:
    explicit admin_course_management(QWidget *parent = nullptr);
    ~admin_course_management();

private:
    Ui::admin_course_management *ui;
};

#endif // ADMIN_COURSE_MANAGEMENT_H
