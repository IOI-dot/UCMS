#include "student.h"
#include <QDebug>

// Static member initialization
QVector<Student> Student::studentList;

// Constructor
Student::Student(const QString& uName, const QString& pass, const QString& mail,
                 const QString& sID, const QString& status)
    : username(uName), password(pass), email(mail), studentID(sID), academicStatus(status) {}

// Getters and Setters
QString Student::getUsername() const { return username; }
void Student::setUsername(const QString& uName) { username = uName; }

QString Student::getPassword() const { return password; }
void Student::setPassword(const QString& pass) { password = pass; }

QString Student::getEmail() const { return email; }
void Student::setEmail(const QString& mail) { email = mail; }

QString Student::getStudentID() const { return studentID; }
void Student::setStudentID(const QString& sID) { studentID = sID; }

QString Student::getAcademicStatus() const { return academicStatus; }
void Student::setAcademicStatus(const QString& status) { academicStatus = status; }

QVector<QString> Student::getRegisteredCourses() const { return registeredCourses; }
void Student::setRegisteredCourses(const QVector<QString>& courses) { registeredCourses = courses; }

// Serialization
QString Student::toString() const {
    QString courses = registeredCourses.join(", ");
    return QString("Username: %1, Email: %2, Student ID: %3, Academic Status: %4, Registered Courses: [%5]")
        .arg(username, email, studentID, academicStatus, courses);
}

bool Student::fromString(const QString& data, Student& student) {
    QStringList parts = data.split(", ");
    student.username = parts[0].mid(QString("Username: ").length());
    student.email = parts[1].mid(QString("Email: ").length());
    student.studentID = parts[2].mid(QString("Student ID: ").length());
    student.academicStatus = parts[3].mid(QString("Academic Status: ").length());
    QString coursesString = parts[4].mid(QString("Registered Courses: [").length());
    coursesString.chop(1);
    student.registeredCourses = coursesString.split(", ", Qt::SkipEmptyParts);
    return true;
}

// Add a student
bool Student::addStudent(const Student& student) {
    for (const Student& existingStudent : studentList) {
        if (existingStudent.getStudentID() == student.getStudentID()) {
            return false; // Duplicate ID
        }
    }
    studentList.append(student);
    return true;
}

// Edit a student
bool Student::editStudent(const QString& studentID, const Student& updatedStudent) {
    for (Student& student : studentList) {
        if (student.getStudentID() == studentID) {
            student = updatedStudent;
            return true;
        }
    }
    return false; // Student ID not found
}

// Remove a student
bool Student::removeStudent(const QString& studentID) {
    for (int i = 0; i < studentList.size(); ++i) {
        if (studentList[i].getStudentID() == studentID) {
            studentList.removeAt(i);
            return true;
        }
    }
    return false; // Student ID not found
}

// Get all students
QVector<Student> Student::getAllStudents() {
    return studentList;
}
