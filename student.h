#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <QVector>
#include <QDebug>

class Student : public User {
private:
    QString studentID;
    QVector<QString> registeredCourses;  // List of course IDs student is registered for
    QString academicStatus;

public:
    // Constructor
    Student(const QString& uName, const QString& pass, const QString& mail, const QString& studentID)
        : User(uName, pass, mail), studentID(studentID), academicStatus("Active") {}
    Student(): User("NONE","BOB","NONE"), studentID('a'), academicStatus("NONE"){}

    // Student-specific methods
    void registerForCourse(const QString& courseID) {
        qDebug() << "Registering for course:" << courseID;
        registeredCourses.append(courseID);
    }

    void viewCourses() const {
        qDebug() << "Available courses:";
    }

    void registerForEvent(const QString& eventID) {
        qDebug() << "Registering for event:" << eventID;
    }

    void viewRegisteredEvents() const {
        qDebug() << "Registered events:";
    }

    // Overridden login method for Student
    bool login(const QString& enteredUsername, const QString& enteredPassword) override {
        return (enteredUsername == username && enteredPassword == password);
    }

    void viewProfile()  override {
        User::viewProfile();
        qDebug() << "Student ID:" << studentID;
        qDebug() << "Academic Status:" << academicStatus;
        qDebug() << "Registered Courses:" << registeredCourses;
    }

    // toString method for Student
    QString toString() {
        QString courses = registeredCourses.join(", ");
        return QString("Student ID: %1, Academic Status: %2, %3, Registered Courses: [%4]")
            .arg(studentID, academicStatus, toString(), courses);
    }
    static bool fromString(const QString& data, Student& student) {
        QStringList parts = data.split(", ");
        if (parts.size() < 5) {
            qWarning() << "Invalid student data format:" << data;
            return false;
        }

        student.username = parts[0];
        student.password = parts[1];
        student.email = parts[2];
        student.studentID = parts[3];
        student.academicStatus = parts[4];

        // Add courses (if any)
        for (int i = 5; i < parts.size(); ++i) {
            student.registeredCourses.append(parts[i]);
        }

        return true;
    }

};

#endif // STUDENT_H
