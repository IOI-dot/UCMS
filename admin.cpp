#include "admin.h"
#include <QDebug>

// Define static members
Admin* Admin::loggedInAdmin = nullptr;
QVector<Admin> Admin::allAdmins;

// Login Methods
bool Admin::login(const QString& enteredUsername, const QString& enteredPassword) {
    for (Admin& admin : allAdmins) {
        if (admin.username == enteredUsername && admin.password == enteredPassword) {
            loggedInAdmin = &admin;  // Save the pointer to the logged-in admin
            return true;
        }
    }
    return false; // No match found
}

bool Admin::verifyLogin(const QString& enteredUsername, const QString& enteredPassword) {
    for (const Admin& admin : allAdmins) {
        if (admin.username == enteredUsername && admin.password == enteredPassword) {
            return true;
        }
    }
    return false;
}

// Course Management
bool Admin::addCourse(const Course& course) {
    return Course::addCourse(course); // Use the static method
}

bool Admin::editCourse(int courseID, const Course& updatedCourse) {
    if (Course::editCourse(courseID, updatedCourse)) {
        return true;
    }
    qWarning() << "Failed to edit course: Course ID" << courseID << "not found.";
    return false;
}

bool Admin::removeCourse(int courseID) {
    if (Course::removeCourse(courseID)) {
        return true;
    }
    qWarning() << "Failed to remove course: Course ID" << courseID << "not found.";
    return false;
}

QVector<Course> Admin::viewCourses() const {
    return Course::getAllCourses();
}

// Student Management
QVector<Student>& Admin::viewStudents() {
    return Student::getAllStudents(); // Return reference to static list
}

bool Admin::editStudent(const QString& studentID, const Student& updatedStudent) {
    if (Student::editStudent(studentID, updatedStudent)) {
        return true;
    }
    qWarning() << "Failed to edit student: Student ID" << studentID << "not found.";
    return false;
}

bool Admin::removeStudent(const QString& studentID) {
    if (Student::removeStudent(studentID)) {
        return true;
    }
    qWarning() << "Failed to remove student: Student ID" << studentID << "not found.";
    return false;
}

// Event Management
bool Admin::addEvent(const Event& event) {
    return Event::addEvent(event);
}

bool Admin::editEvent(int eventID, const Event& updatedEvent) {
    if (Event::editEvent(eventID, updatedEvent)) {
        return true;
    }
    qWarning() << "Failed to edit event: Event ID" << eventID << "not found.";
    return false;
}

bool Admin::removeEvent(int eventID) {
    if (Event::removeEvent(eventID)) {
        return true;
    }
    qWarning() << "Failed to remove event: Event ID" << eventID << "not found.";
    return false;
}

QVector<Event> Admin::viewEvents() const {
    return Event::getAllEvents();
}

// Load Admin Data
void Admin::loadAdminDataFromFile(const QVector<Admin>& admins) {
    allAdmins = admins; // Overwrite the static list with the new data
}
