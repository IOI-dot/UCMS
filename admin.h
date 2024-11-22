#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "course.h"
#include "student.h"
#include "event.h"

class Admin : public User {
public:
        // Static vector to store all admins
    static QVector<Admin> allAdmins;
    // Constructor: Initialize admin with username, password, and email
    Admin(const QString& username, const QString& password, const QString& email)
        : User(username, password, email) {}

    // Override the login method from the User class
    // Static method to verify login credentials across all admins
    bool login(const QString& enteredUsername, const QString& enteredPassword) {
        // Iterate over all admins in the static vector `allAdmins`
        for (const Admin& admin : allAdmins) {
            if (admin.username == enteredUsername && admin.password == enteredPassword) {
                return true;  // If the username and password match, return true
            }
        }
        return false;  // If no match is found, return false
    }
    // Course management
    bool addCourse(const Course& course);
    bool editCourse(int courseID, const Course& updatedCourse);
    bool removeCourse(int courseID);
    QVector<Course> viewCourses() const;

    // Student management
    QVector<Student> viewStudents() const;
    bool editStudent(int studentID, const Student& updatedStudent);
    bool removeStudent(int studentID);

    // Event management
    bool addEvent(const Event& event);
    bool editEvent(int eventID, const Event& updatedEvent);
    bool removeEvent(int eventID);
    QVector<Event> viewEvents() const;
    // Static method to populate allAdmins vector with data
    static void loadAdminDataFromFile(const QVector<Admin>& admins) {
        allAdmins = admins;  // Populate the static vector with the loaded admin data
    }

    // Static method to verify login credentials
    static bool verifyLogin(const QString& enteredUsername, const QString& enteredPassword) {
        for (const Admin& admin : allAdmins) {
            if (admin.username == enteredUsername && admin.password == enteredPassword) {
                return true;
            }
        }
        return false;
    }
};

#endif // ADMIN_H
