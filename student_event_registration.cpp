#include "student_event_registration.h"
#include "ui_student_event_registration.h"
#include <QMessageBox>
#include "student.h"
#include "student_homepage.h"

student_event_registration::student_event_registration(Student* student, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_event_registration),
    currentStudent(student)  // Store the student pointer
{
    ui->setupUi(this);

    // Populate the table with available events
    populateEvents();

    // Populate the Registration list with events the student is already registered for
    populateRegistrationList();

    // Connect the "Register" button click signal to the corresponding slot
    connect(ui->PushADD, &QPushButton::clicked, this, &student_event_registration::on_registerButton_clicked);

    // Connect the event selection change signal to the corresponding slot
    connect(ui->TABLECOURSES, &QTableWidget::itemSelectionChanged, this, &student_event_registration::on_eventSelectionChanged);

    // Connect the back button to the corresponding slot
    connect(ui->Back, &QPushButton::clicked, this, &student_event_registration::on_Back_clicked);
}

student_event_registration::~student_event_registration()
{
    delete ui;
}

void student_event_registration::populateEvents()
{
    // Fetch all events
    QVector<Event> events = Event::getAllEvents();

    // Set up the table to display event information (4 columns now)
    ui->TABLECOURSES->setRowCount(events.size());
    ui->TABLECOURSES->setColumnCount(4);  // Now showing: Title, Description, Date, CRN
    ui->TABLECOURSES->setHorizontalHeaderLabels(QStringList() << "Event Title" << "Description" << "Date" << "CRN");

    // Populate the table with event data
    for (int i = 0; i < events.size(); ++i) {
        const Event &event = events[i];

        // Set event title and description
        ui->TABLECOURSES->setItem(i, 0, new QTableWidgetItem(event.getEventTitle()));
        ui->TABLECOURSES->setItem(i, 1, new QTableWidgetItem(event.getEventDescription()));

        // Format and display event date
        QString eventDate = event.getEventDate(); // Assuming date is in string format (e.g., "2024-12-15")
        ui->TABLECOURSES->setItem(i, 2, new QTableWidgetItem(eventDate));

        // Format guest speakers and CRN
        QString guestSpeakers = event.getGuestSpeakers().join(", ");
        if (guestSpeakers.isEmpty()) guestSpeakers = "None"; // Display "None" if no speakers
        ui->TABLECOURSES->setItem(i, 3, new QTableWidgetItem(guestSpeakers + ", CRN: " + QString::number(event.getEventID())));
    }
}

void student_event_registration::populateRegistrationList()
{
    // Clear the list first
    ui->Registrationlist->clear();

    // Add each registered event to the Registration list
    for (const QString &event : currentStudent->getRegisteredEvents()) {
        ui->Registrationlist->addItem(event);
    }
}

void student_event_registration::on_registerButton_clicked()
{
    // Get the selected event from the table
    QList<QTableWidgetItem *> selectedItems = ui->TABLECOURSES->selectedItems();

    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select an event to register.");
        return;
    }

    // Get the event title from the selected row
    int row = selectedItems.first()->row();
    QString eventTitle = ui->TABLECOURSES->item(row, 0)->text();

    // Check if the student is already registered for this event
    if (currentStudent->getRegisteredEvents().contains(eventTitle)) {
        QMessageBox::warning(this, "Already Registered", "You are already registered for this event.");
        return;
    }

    // Register the student for this event
    QVector<QString> registeredEvents = currentStudent->getRegisteredEvents();
    registeredEvents.append(eventTitle);  // Add the selected event to the registered events
    currentStudent->setRegisteredEvents(registeredEvents);

    QMessageBox::information(this, "Registration Successful", "You have been successfully registered for the event: " + eventTitle);
    populateRegistrationList();  // Refresh the list of registered events
}

void student_event_registration::on_eventSelectionChanged()
{
    // Handle event selection change if needed
}

void student_event_registration::on_Back_clicked()
{
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}
