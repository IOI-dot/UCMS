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
    QVector<QString> registeredCourses;


public:
    // Static storage for all students
    static QVector<Student> studentList;
    // Constructor
    Student(const QString& uName = "", const QString& pass = "", const QString& mail = "",
            const QString& sID = "", const QString& status = "");
    // Static method to verify login credentials across all students
  static  bool verifyLogin(const QString& enteredUsername, const QString& enteredStudentID) {
        // Iterate over all students in the static vector `studentList`
        for (const Student& student : studentList) {
            if (student.getUsername() == enteredUsername && student.getStudentID() == enteredStudentID) {
                return true;  // If the username and student ID match, return true
            }
        }
        return false;  // If no match is found, return false
    }

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

    // Serialization
    QString toString() const;
    static bool fromString(const QString& data, Student& student);

    // Student management methods
    static bool addStudent(const Student& student);
    static bool editStudent(const QString& studentID, const Student& updatedStudent);
    static bool removeStudent(const QString& studentID);
    static QVector<Student> getAllStudents();
};

#endif // STUDENT_H
