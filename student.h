#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QVector>
#include <QDebug>
class Student {
private:
    QString username;
    QString password;
    QString email;
    QString studentID;
    QString academicStatus;
    QVector<QString> registeredCourses;  // Registered courses for the student
    QVector<QString> registeredEvents;   // Registered events for the student
    QVector<QString> completedPrerequisites;  // Prerequisites completed by the student


public:
    static QVector<Student> studentList;  // Static list of all students
    static Student* loggedInStudent;  // Static variable for logged-in student
    static QVector<QString> currentStudentPrerequisites;
    // Constructor
    Student(const QString& uName = "", const QString& mail = "", const QString& ID = "",
            const QString& status = "", const QString& courses = "");

    // Getters and Setters
    QString getUsername() const;
    void setUsername(const QString& uName);
    // Getter for completed prerequisites
    QVector<QString> getCompletedPrerequisites() const {
        return completedPrerequisites;
    }

    // Setter for completed prerequisites
    void setCompletedPrerequisites(const QVector<QString>& prerequisites) {
        completedPrerequisites = prerequisites;

        // Update static prerequisites for global use
        currentStudentPrerequisites = prerequisites;
    }

    // Static Getter
    static QVector<QString> getCurrentStudentPrerequisites() {
        return currentStudentPrerequisites;
    }

    // Static Setter
    static void setCurrentStudentPrerequisites(const QVector<QString>& prerequisites) {
        currentStudentPrerequisites = prerequisites;
    }
    QString getEmail() const;
    void setEmail(const QString& mail);

    QString getStudentID() const;
    void setStudentID(const QString& ID);

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
        // Iterate over all students in the static vector studentList
        for (int i = 0; i < studentList.size(); ++i) {
            const Student& student = studentList[i];  // Use reference to avoid unnecessary copying

            // Debug: Log current student details being checked
            qDebug() << "Checking student: Username =" << student.getUsername()
                     << ", StudentID =" << student.getStudentID();

            if (student.getUsername() == enteredUsername && student.getStudentID() == enteredStudentID) {
                // If login is successful, update loggedInStudent
                loggedInStudent = const_cast<Student*>(&student);  // Safe here, since studentList holds all objects

                // Debug: Log successful login
                qDebug() << "Login successful for student: Username =" << student.getUsername();

                // After logging in, you can directly access the student's registered courses and events
                qDebug() << "Registered Courses: " << student.getRegisteredCourses().join(", ");
                qDebug() << "Registered Events: " << student.getRegisteredEvents().join(", ");

                return true;  // Credentials match, login successful
            }
        }

        // If no match is found, log the failure
        qDebug() << "Login failed: No matching student found for Username =" << enteredUsername
                 << ", StudentID =" << enteredStudentID;
        return false;  // No match found, login failed
    }



};

#endif // STUDENT_H
