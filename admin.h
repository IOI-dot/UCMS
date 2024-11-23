#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "course.h"
#include "student.h"
#include "event.h"

class Admin : public User {
public:
    static Admin* loggedInAdmin;         // Pointer to the logged-in admin
    static QVector<Admin> allAdmins;    // Static vector to store all admins

    // Constructor
    Admin(const QString& username, const QString& password, const QString& email)
        : User(username, password, email) {}

    // Login Methods
    bool login(const QString& enteredUsername, const QString& enteredPassword);
    static bool verifyLogin(const QString& enteredUsername, const QString& enteredPassword);

    // Course Management
    bool addCourse(const Course& course);
    bool editCourse(int courseID, const Course& updatedCourse);
    bool removeCourse(int courseID);
    QVector<Course> viewCourses() const;

    // Student Management
    QVector<Student>& viewStudents();
    bool editStudent(const QString& studentID, const Student& updatedStudent);
    bool removeStudent(const QString& studentID);

    // Event Management
    bool addEvent(const Event& event);
    bool editEvent(int eventID, const Event& updatedEvent);
    bool removeEvent(int eventID);
    QVector<Event> viewEvents() const;

    // Load Admin Data
    static void loadAdminDataFromFile(const QVector<Admin>& admins);
};

#endif // ADMIN_H
