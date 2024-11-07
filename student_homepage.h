#ifndef STUDENT_HOMEPAGE_H
#define STUDENT_HOMEPAGE_H

#include <QDialog>

namespace Ui {
class student_homepage;
}

class student_homepage : public QDialog
{
    Q_OBJECT

public:
    explicit student_homepage(QWidget *parent = nullptr);
    ~student_homepage();

private slots:
    void on_course_regis_pushButton_clicked();

    void on_event_regis_pushButton_clicked();

    void on_academic_profile_pushButton_clicked();

private:
    Ui::student_homepage *ui;
};

#endif // STUDENT_HOMEPAGE_H
