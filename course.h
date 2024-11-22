#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QStringList>
#include <QVector>

class Course {
private:
    QString courseID;        // Unique course identifier
    QString name;            // Course name
    QString department;      // Department offering the course
    QString instructor;      // Course instructor
    QString schedule;        // Course schedule
    QVector<QString> prerequisites;  // List of prerequisite course IDs

public:
    // Constructors
    Course();
    Course(const QString& id, const QString& name, const QString& department,
           const QString& instructor, const QString& schedule,
           const QVector<QString>& prerequisites);

    // Getters
    QString getCourseID() const;
    QString getName() const;
    QString getDepartment() const;
    QString getInstructor() const;
    QString getSchedule() const;
    QVector<QString> getPrerequisites() const;

    // Setters
    void setCourseID(const QString& id);
    void setName(const QString& name);
    void setDepartment(const QString& department);
    void setInstructor(const QString& instructor);
    void setSchedule(const QString& schedule);
    void setPrerequisites(const QVector<QString>& prerequisites);

    // Serialization and Deserialization
    QString toString() const;
    bool fromString(const QString& data);

    // Utility Functions
    bool hasPrerequisite(const QString& prerequisite) const;
    // New course management methods
    static bool addCourse(const Course& course);
   static bool editCourse(int courseID, const Course& updatedCourse);
  static  bool removeCourse(int courseID);
   static QVector<Course> getAllCourses();
    // Static storage for all courses
    static QVector<Course> courseList;
};

#endif // COURSE_H
