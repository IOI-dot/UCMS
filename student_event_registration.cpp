#include "student_event_registration.h"
#include "ui_student_event_registration.h"
#include <QMessageBox>
#include <QDebug>
#include "student.h"

student_event_registration::student_event_registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_event_registration)
{
    ui->setupUi(this);

    // Populate the table with available events
    populateEvents();

    // Populate the Registrationlist with events the student is already registered for
    populateRegistrationList();

    // Connect the "Register" button click signal to the corresponding slot
    connect(ui->PushADD, &QPushButton::clicked, this, &student_event_registration::on_registerButton_clicked);

    // Connect the event selection change signal to the corresponding slot
    connect(ui->TABLECOURSES, &QTableWidget::itemSelectionChanged, this, &student_event_registration::on_eventSelectionChanged);
}

student_event_registration::~student_event_registration()
{
    delete ui;
}

void student_event_registration::populateEvents()
{
    // Get all available events (assuming Event::getAllEvents() returns a QVector<Event>)
    QVector<Event> events = Event::getAllEvents();

    ui->TABLECOURSES->setRowCount(events.size());
    ui->TABLECOURSES->setColumnCount(2);  // Columns for Name, Description
    ui->TABLECOURSES->setHorizontalHeaderLabels(QStringList() << "Event Title" << "Description");

    for (int i = 0; i < events.size(); ++i) {
        const Event &event = events[i];

        // Populate the table with event details
        ui->TABLECOURSES->setItem(i, 0, new QTableWidgetItem(event.getEventTitle()));
        ui->TABLECOURSES->setItem(i, 1, new QTableWidgetItem(event.getEventDescription()));
    }
}

void student_event_registration::populateRegistrationList()
{
    // Get the logged-in student
    Student *currentStudent = Student::getLoggedInStudent();

    // Clear the list first
    ui->Registrationlist->clear();

    // Add each registered event to the Registrationlist
    for (const QString &event : currentStudent->getRegisteredEvents()) {
        ui->Registrationlist->addItem(event);
    }
}

void student_event_registration::on_registerButton_clicked()
{
    // Get the selected row in the table
    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();

    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select an event to register.");
        return;
    }

    // Get event details from the selected row
    int row = selectedItems.first()->row();
    QString eventTitle = ui->TABLECOURSES->item(row, 0)->text();

    // Register the student for the event
    Student *currentStudent = Student::getLoggedInStudent();
    QVector<QString> registeredEvents = currentStudent->getRegisteredEvents();
    registeredEvents.append(eventTitle);  // Add selected event to registered events
    currentStudent->setRegisteredEvents(registeredEvents);  // Update the student's registered events

    // Display confirmation message
    QMessageBox::information(this, "Registration Successful", "You have been successfully registered for the event: " + eventTitle);

    // Optionally, update the registration list (or refresh UI)
    populateRegistrationList();  // Refresh the list of registered events
}


void student_event_registration::on_eventSelectionChanged()
{
    // Update any information
}
