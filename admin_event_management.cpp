#include "admin_event_management.h"
#include "ui_admin_event_management.h"
#include "event.h"
#include "file_manager.h"
#include <QMessageBox>
#include <QDebug>

admin_event_management::admin_event_management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_event_management) {
    ui->setupUi(this);

    // Initialize File_Manager instance
    File_Manager fileManager;

    // Load events from file
    QVector<Event> loadedEvents = fileManager.loadEventData();

    // Store the events in the static event list of the Event class
    Event::eventList = loadedEvents;
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

            // Refresh the UI to show updated events
            refreshUI();
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
                // Refresh the UI after deletion
                refreshUI();
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

// Refresh the UI to display events
void admin_event_management::refreshUI() {
    // The refreshUI method now displays the events from Event::eventList directly
    // You can further populate UI components with event information if needed
}
