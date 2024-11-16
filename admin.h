#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include <QDebug>
class Admin : public User {
private:
    QString adminID;

public:
    // Constructor
    Admin(const QString& uName, const QString& pass, const QString& mail, const QString& adminID)
        : User(uName, pass, mail), adminID(adminID) {}

    // Admin-specific methods
    void manageCourse() {
        qDebug() << "Managing courses...";
    }

    void manageStudent() {
        qDebug() << "Managing student profiles...";
    }

    void manageEvent() {
        qDebug() << "Managing academic events...";
    }

    // Overridden login method for Admin
    bool login(const QString& enteredUsername, const QString& enteredPassword) override {
        return (enteredUsername == username && enteredPassword == password);
    }

    void viewProfile() override {
        User::viewProfile();
        qDebug() << "Admin ID:" << adminID;
    }

};

#endif // ADMIN_H
