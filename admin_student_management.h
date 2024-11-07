#ifndef ADMIN_STUDENT_MANAGEMENT_H
#define ADMIN_STUDENT_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class admin_student_management;
}

class admin_student_management : public QDialog
{
    Q_OBJECT

public:
    explicit admin_student_management(QWidget *parent = nullptr);
    ~admin_student_management();

private:
    Ui::admin_student_management *ui;
};

#endif // ADMIN_STUDENT_MANAGEMENT_H
