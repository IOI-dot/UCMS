#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QVector>

class Event {
private:
    QString eventTitle;
    QString eventDescription;
    QString eventDate;
    QVector<QString> guestSpeakers;
    int ID;

    // Static storage for all events
    static QVector<Event> eventList;

public:
    // Constructors
    Event();
    Event(const QString& title, const QString& description, const QString& date,
          const QVector<QString>& speakers, const int CRN);

    // Getters and Setters
    QString getEventTitle() const { return eventTitle; }
    void setEventTitle(const QString& title) { eventTitle = title; }

    QString getEventDescription() const { return eventDescription; }
    void setEventDescription(const QString& description) { eventDescription = description; }

    QString getEventDate() const { return eventDate; }
    void setEventDate(const QString& date) { eventDate = date; }

    QVector<QString> getGuestSpeakers() const { return guestSpeakers; }
    void setGuestSpeakers(const QVector<QString>& speakers) { guestSpeakers = speakers; }

    int getEventID() const { return ID; }
    void setEventID(int crn) { ID = crn; }

    // Serialization
    QString toString() const;
    static bool fromString(const QString& data, Event& event);

    // Event management methods
    static bool addEvent(const Event& event);
    static bool editEvent(int eventID, const Event& updatedEvent);
    static bool removeEvent(int eventID);
    static QVector<Event> getAllEvents();
};

#endif // EVENT_H
