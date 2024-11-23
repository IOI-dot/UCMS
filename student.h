#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QVector>

class Student {
private:
    QString username;
    QString password;
    QString email;
    QString studentID;
    QString academicStatus;
    QVector<QString> registeredCourses;  // Registered courses for the student
    QVector<QString> registeredEvents;   // Registered events for the student
public:
    static QVector<Student> studentList;  // Static list of all students
    static Student* loggedInStudent;  // Static variable for logged-in student

    // Constructor
    Student(const QString& uName = "", const QString& pass = "", const QString& mail = "",
            const QString& sID = "", const QString& status = "");

    // Getters and Setters
    QString getUsername() const;
    void setUsername(const QString& uName);

    QString getPassword() const;
    void setPassword(const QString& pass);

    QString getEmail() const;
    void setEmail(const QString& mail);

    QString getStudentID() const;
    void setStudentID(const QString& sID);

    QString getAcademicStatus() const;
    void setAcademicStatus(const QString& status);

    QVector<QString> getRegisteredCourses() const;
    void setRegisteredCourses(const QVector<QString>& courses);

    QVector<QString> getRegisteredEvents() const;  // Add this getter
    void setRegisteredEvents(const QVector<QString>& events);  // Add this setter

    // Serialization (Convert student object to string and vice versa)
    QString toString() const;
    static bool fromString(const QString& data, Student& student);

    // Student management methods
    static void addStudent(const Student& student);  // Add a student to the list
    static bool editStudent(const QString& studentID, const Student& updatedStudent);  // Edit student details
    static bool removeStudent(const QString& studentID);  // Remove student from the list
    static QVector<Student>& getAllStudents();  // Get all students

    static void setLoggedInStudent(Student& student) {
        if (!loggedInStudent) {
            loggedInStudent = &student;  // Store the reference to the student
        }
    }
    static Student* getLoggedInStudent() {
        return loggedInStudent;
    }
    static bool verifyLogin(const QString& enteredUsername, const QString& enteredStudentID) {
        // Iterate over all students in the static vector `studentList`
        for (int i = 0; i < studentList.size(); ++i) {
            // Use reference to avoid making copies and ensure direct access
            const Student& student = studentList[i];

            if (student.getUsername() == enteredUsername && student.getStudentID() == enteredStudentID) {
                return true;  // If the username and student ID match, return true
            }
        }
        return false;  // If no match is found, return false
    }

};

#endif // STUDENT_H
