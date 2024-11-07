#ifndef STUDENT_EVENT_REGISTRATION_H
#define STUDENT_EVENT_REGISTRATION_H

#include <QDialog>

namespace Ui {
class student_event_registration;
}

class student_event_registration : public QDialog
{
    Q_OBJECT

public:
    explicit student_event_registration(QWidget *parent = nullptr);
    ~student_event_registration();

private:
    Ui::student_event_registration *ui;
};

#endif // STUDENT_EVENT_REGISTRATION_H
