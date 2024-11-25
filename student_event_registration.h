#ifndef STUDENT_EVENT_REGISTRATION_H
#define STUDENT_EVENT_REGISTRATION_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QListWidget>
#include <QLabel>
#include "event.h"
#include "student.h"

namespace Ui {
class student_event_registration;
}

class student_event_registration : public QDialog
{
    Q_OBJECT

public:
    explicit student_event_registration(Student* student, QWidget *parent = nullptr);  // Pass Student pointer to the constructor
    ~student_event_registration();

private slots:
    void on_registerButton_clicked();  // Slot for Register button click
    void on_eventSelectionChanged();  // Slot for event selection change
    void on_Back_clicked();  // Slot for back button click

private:
    Ui::student_event_registration *ui;
    Student* currentStudent;  // Pointer to the logged-in student

    void populateEvents();  // Populate event table with available events
    void populateRegistrationList();  // Populate registration list with student's registered events
};

#endif // STUDENT_EVENT_REGISTRATION_H
