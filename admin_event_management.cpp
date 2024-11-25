#include "admin_event_management.h"
#include "ui_admin_event_management.h"
#include "event.h"
#include "file_manager.h"
#include <QMessageBox>
#include <QDebug>
#include "admin_homepage.h"  // Include the header for admin_homepage
// Constructor accepting an Admin* parameter
admin_event_management::admin_event_management(Admin* admin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_event_management),
    currentAdmin(admin)  // Initialize the currentAdmin pointer with the passed Admin object
{
    ui->setupUi(this);

    // Initialize File_Manager instance
    File_Manager fileManager;

    // Load events from file
    QVector<Event> loadedEvents = fileManager.loadEventData();

    // Store the events in the static event list of the Event class
    Event::eventList = loadedEvents;
    // Connect the Back button to the slot
    connect(ui->Back, &QPushButton::clicked, this, &admin_event_management::on_Back_clicked);
}

// Destructor
admin_event_management::~admin_event_management() {
    delete ui;
}

// Add an event
void admin_event_management::on_ADD_clicked() {
    QString title = ui->ADDTITLE->text();
    QString description = ui->ADDDDESCRIPTION->text();
    QString date = ui->ADDDATE->text();
    QVector<QString> speakers = ui->ADDSPEAKERS->text().split(",", Qt::SkipEmptyParts);
    QString crn = ui->ADDCRN->text();

    // Check if all fields are filled
    if (title.isEmpty() || description.isEmpty() || date.isEmpty() || speakers.isEmpty() || crn.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all the fields.");
        return;  // Exit the function if any field is empty
    }

    // Create the new event
    Event newEvent(title, description, date, speakers, crn.toInt());

    // Try to add the event using the static addEvent method
    if (!Event::addEvent(newEvent)) {
        QMessageBox::warning(this, "Error", "Event with this CRN already exists!");
        return;
    }

    // Refresh the UI
    refreshUI();

    // Clear input fields
    ui->ADDTITLE->clear();
    ui->ADDDDESCRIPTION->clear();
    ui->ADDDATE->clear();
    ui->ADDSPEAKERS->clear();
    ui->ADDCRN->clear();

    QMessageBox::information(this, "Success", "Event added successfully!");
}

// Edit an event
void admin_event_management::on_EDIT_clicked() {
    QString crn = ui->ADDCRN_2->text();  // Get the CRN entered by the user

    // Check if CRN field is empty
    if (crn.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a CRN to edit.");
        return;  // Exit the function if CRN is empty
    }

    bool eventFound = false;

    // Search for the event with the entered CRN
    for (Event& event : Event::eventList) {
        if (event.getEventID() == crn.toInt()) {
            eventFound = true;  // Event exists, so we can edit it

            // Check if any fields are left empty
            if (ui->ADDDDESCRIPTION_2->text().isEmpty() || ui->ADDDATE_2->text().isEmpty() ||
                ui->ADDSPEAKERS_2->text().isEmpty()) {
                QMessageBox::warning(this, "Error", "Please fill in all fields before saving.");
                return;  // Exit the function if any field is empty
            }

            // Update the event with new values
            event.setEventTitle(ui->ADDTITLE_2->text());
            event.setEventDescription(ui->ADDDDESCRIPTION_2->text());
            event.setEventDate(ui->ADDDATE_2->text());
            event.setGuestSpeakers(ui->ADDSPEAKERS_2->text().split(",", Qt::SkipEmptyParts));

            // Refresh the UI
            refreshUI();

            // Clear input fields
            ui->ADDTITLE_2->clear();
            ui->ADDDDESCRIPTION_2->clear();
            ui->ADDDATE_2->clear();
            ui->ADDSPEAKERS_2->clear();
            ui->ADDCRN_2->clear();
            QMessageBox::information(this, "Success", "Event edited successfully!");
            return;  // Exit the function once the event is updated
        }
    }

    // If the event with the entered CRN is not found
    if (!eventFound) {
        QMessageBox::warning(this, "Error", "Event with the given CRN not found!");
    }
}

// Delete an event
void admin_event_management::on_DELETE_clicked() {
    QString crn = ui->Deletedit->text();

    // Check if the event exists
    bool eventFound = false;
    for (int i = 0; i < Event::eventList.size(); ++i) {
        if (Event::eventList[i].getEventID() == crn.toInt()) {
            eventFound = true;
            // Try to remove the event using the static removeEvent method
            if (Event::removeEvent(crn.toInt())) {
                // Refresh the UI
                refreshUI();

                // Clear input fields
                ui->Deletedit->clear();
                QMessageBox::information(this, "Success", "Event deleted successfully!");
            }
            break;
        }
    }

    // If event is not found
    if (!eventFound) {
        QMessageBox::warning(this, "Error", "Event ID not found! Please enter a valid CRN.");
    }
}
// Slot for the Back button click
void admin_event_management::on_Back_clicked() {
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}
// Refresh the UI to display events
void admin_event_management::refreshUI() {
    // The refreshUI method now displays the events from Event::eventList directly
    // You can further populate UI components with event information if needed
}
