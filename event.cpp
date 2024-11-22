#include "event.h"
#include <QDebug>

// Static member initialization
QVector<Event> Event::eventList;

// Constructors
Event::Event() {}
Event::Event(const QString& title, const QString& description, const QString& date,
             const QVector<QString>& speakers, const int CRN)
    : eventTitle(title), eventDescription(description), eventDate(date), guestSpeakers(speakers), ID(CRN) {}

// Convert event data to string
QString Event::toString() const {
    QString speakers = guestSpeakers.join(", ");
    return QString("Event Title: %1, Description: %2, Date: %3, Guest Speakers: [%4]")
        .arg(eventTitle, eventDescription, eventDate, speakers);
}

// Convert a string to an Event object
bool Event::fromString(const QString& data, Event& event) {
    QStringList parts = data.split(", ");
    if (parts.size() < 4) {
        qWarning() << "Invalid event data format:" << data;
        return false;
    }
    // Extract fields
    event.eventTitle = parts[0].mid(QString("Event Title: ").length());
    event.eventDescription = parts[1].mid(QString("Description: ").length());
    event.eventDate = parts[2].mid(QString("Date: ").length());
    QString speakersString = parts[3].mid(QString("Guest Speakers: [").length());
    speakersString.chop(1); // Remove trailing ']'
    event.guestSpeakers = speakersString.split(", ", Qt::SkipEmptyParts);

    return true;
}

// Add an event
bool Event::addEvent(const Event& event) {
    for (const Event& existingEvent : eventList) {
        if (existingEvent.getEventID() == event.getEventID()) {
            return false; // Duplicate ID
        }
    }
    eventList.append(event);
    return true;
}

// Edit an event
bool Event::editEvent(int eventID, const Event& updatedEvent) {
    for (Event& event : eventList) {
        if (event.getEventID() == eventID) {
            event = updatedEvent;
            return true;
        }
    }
    return false; // Event ID not found
}

// Remove an event
bool Event::removeEvent(int eventID) {
    for (int i = 0; i < eventList.size(); ++i) {
        if (eventList[i].getEventID() == eventID) {
            eventList.removeAt(i);
            return true;
        }
    }
    return false; // Event ID not found
}

// Get all events
QVector<Event> Event::getAllEvents() {
    return eventList;
}
