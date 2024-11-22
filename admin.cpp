#include "admin.h"
#include <QDebug>
// Define the static member variable
Admin* Admin::loggedInAdmin = nullptr; // Static member initialization
QVector<Admin> Admin::allAdmins;
// Course Management
bool Admin::addCourse(const Course& course) {
    return Course::addCourse(course); // Use the static method in Course
}

bool Admin::editCourse(int courseID, const Course& updatedCourse) {
    if (Course::editCourse(courseID, updatedCourse)) {
        return true;
    }
    qWarning() << "Course ID not found: " << courseID;
    return false;
}

bool Admin::removeCourse(int courseID) {
    if (Course::removeCourse(courseID)) {
        return true;
    }
    qWarning() << "Course ID not found: " << courseID;
    return false;
}

QVector<Course> Admin::viewCourses() const {
    return Course::getAllCourses(); // Get all courses using the static method
}

// Student Management
QVector<Student> Admin::viewStudents() const {
    return Student::getAllStudents(); // Get all students using the static method
}

bool Admin::editStudent(int studentID, const Student& updatedStudent) {
    if (Student::editStudent(QString::number(studentID), updatedStudent)) {
        return true;
    }
    qWarning() << "Student ID not found: " << studentID;
    return false;
}

bool Admin::removeStudent(int studentID) {
    if (Student::removeStudent(QString::number(studentID))) {
        return true;
    }
    qWarning() << "Student ID not found: " << studentID;
    return false;
}

// Event Management
bool Admin::addEvent(const Event& event) {
    return Event::addEvent(event); // Use the static method in Event
}

bool Admin::editEvent(int eventID, const Event& updatedEvent) {
    if (Event::editEvent(eventID, updatedEvent)) {
        return true;
    }
    qWarning() << "Event ID not found: " << eventID;
    return false;
}

bool Admin::removeEvent(int eventID) {
    if (Event::removeEvent(eventID)) {
        return true;
    }
    qWarning() << "Event ID not found: " << eventID;
    return false;
}

QVector<Event> Admin::viewEvents() const {
    return Event::getAllEvents(); // Get all events using the static method
}
