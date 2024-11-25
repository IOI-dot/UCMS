#include "student.h"
#include <QDebug>

// Static member initialization
QVector<Student> Student::studentList;  // This stores all students
Student* Student::loggedInStudent = nullptr;  // This points to the currently logged-in student
Student::Student(const QString& uName, const QString& mail, const QString& ID,
                 const QString& status, const QString& courses) {
    username = uName;
    email = mail;
    studentID = ID;
    academicStatus = status;

    // If the courses string is not empty, split it into a list of courses
    if (!courses.isEmpty()) {
        registeredCourses = courses.split(", ", Qt::SkipEmptyParts);
    }
}

QVector<QString> Student::getCompletedPrerequisites() const {
    qDebug() << "Getting" << completedPrerequisites.join(", ");
    return completedPrerequisites;
}
QVector<QString> Student::currentStudentPrerequisites;

void Student::setCompletedPrerequisites(const QVector<QString>& prerequisites) {
    completedPrerequisites = prerequisites;
}
// Getters and Setters
QString Student::getUsername() const { return username; }
void Student::setUsername(const QString& uName) { username = uName; }

QString Student::getEmail() const { return email; }
void Student::setEmail(const QString& mail) { email = mail; }

QString Student::getStudentID() const { return studentID; }
void Student::setStudentID(const QString& ID) { studentID = ID; }

QString Student::getAcademicStatus() const { return academicStatus; }
void Student::setAcademicStatus(const QString& status) { academicStatus = status; }

QVector<QString> Student::getRegisteredCourses() const { return registeredCourses; }
void Student::setRegisteredCourses(const QVector<QString>& courses) { registeredCourses = courses; }

QVector<QString> Student::getRegisteredEvents() const { return registeredEvents; }
void Student::setRegisteredEvents(const QVector<QString>& events) { registeredEvents = events; }

QString Student::toString() const {
    // Convert registered courses, events, and completed prerequisites to comma-separated strings
    QString courses = registeredCourses.isEmpty() ? "" : registeredCourses.join(" | ");
    QString events = registeredEvents.isEmpty() ? "" : registeredEvents.join(" | ");
    QString prerequisites = completedPrerequisites.isEmpty() ? "" : completedPrerequisites.join(" | ");

    return QString("Username: %1, Email: %2, Student ID: %3, Academic Status: %4, Registered Courses: [%5], Registered Events: [%6], Completed Prerequisites: [%7]")
        .arg(username, email, studentID, academicStatus, courses, events, prerequisites);
}


bool Student::fromString(const QString& data, Student& student) {
    QStringList parts = data.split(", ");
    student.username = parts[0].mid(QString("Username: ").length());
    student.email = parts[1].mid(QString("Email: ").length());
    student.studentID = parts[2].mid(QString("Student ID: ").length());
    student.academicStatus = parts[3].mid(QString("Academic Status: ").length());

    QString coursesString = parts[4].mid(QString("Registered Courses: [").length());
    coursesString.chop(1);  // Remove closing bracket
    student.registeredCourses = coursesString.split(", ", Qt::SkipEmptyParts);

    QString eventsString = parts[5].mid(QString("Registered Events: [").length());
    eventsString.chop(1);  // Remove closing bracket
    student.registeredEvents = eventsString.split(", ", Qt::SkipEmptyParts);

    QString prerequisitesString = parts[6].mid(QString("Completed Prerequisites: [").length());
    prerequisitesString.chop(1);  // Remove closing bracket
    student.completedPrerequisites = prerequisitesString.split(", ", Qt::SkipEmptyParts);

    return true;
}



// Add a student to the student list
void Student::addStudent(const Student &student) {
    studentList.append(student);
}

// Edit an existing student in the list
bool Student::editStudent(const QString& studentID, const Student& updatedStudent) {
    for (Student& student : studentList) {
        if (student.getStudentID() == studentID) {
            student = updatedStudent;
            return true;
        }
    }
    return false;  // Student ID not found
}

// Remove a student from the list
bool Student::removeStudent(const QString& studentID) {
    for (int i = 0; i < studentList.size(); ++i) {
        if (studentList[i].getStudentID() == studentID) {
            studentList.removeAt(i);
            return true;
        }
    }
    return false;  // Student ID not found
}

// Get all students
QVector<Student>& Student::getAllStudents() {
    return studentList;
}



