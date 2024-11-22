#include "course.h"
QVector<Course> Course::courseList; // Definition of the static member
// Default Constructor
Course::Course() {}

// Parameterized Constructor
Course::Course(const QString& id, const QString& name, const QString& department,
               const QString& instructor, const QString& schedule,
               const QVector<QString>& prerequisites)
    : courseID(id), name(name), department(department),
    instructor(instructor), schedule(schedule), prerequisites(prerequisites) {}

// Getters
QString Course::getCourseID() const { return courseID; }
QString Course::getName() const { return name; }
QString Course::getDepartment() const { return department; }
QString Course::getInstructor() const { return instructor; }
QString Course::getSchedule() const { return schedule; }
QVector<QString> Course::getPrerequisites() const { return prerequisites; }

// Setters
void Course::setCourseID(const QString& id) { courseID = id; }
void Course::setName(const QString& name) { this->name = name; }
void Course::setDepartment(const QString& department) { this->department = department; }
void Course::setInstructor(const QString& instructor) { this->instructor = instructor; }
void Course::setSchedule(const QString& schedule) { this->schedule = schedule; }
void Course::setPrerequisites(const QVector<QString>& prerequisites) { this->prerequisites = prerequisites; }

// Serialize to a string
QString Course::toString() const {
    QString prerequisitesString = prerequisites.join(",");  // Combine prerequisites into a single string
    return courseID + "|" + name + "|" + department + "|" + instructor + "|" + schedule + "|" + prerequisitesString;
}

// Deserialize from a string
bool Course::fromString(const QString& data) {
    QStringList parts = data.split("|");
    if (parts.size() != 6) {
        return false;  // Invalid format
    }

    courseID = parts[0];
    name = parts[1];
    department = parts[2];
    instructor = parts[3];
    schedule = parts[4];
    prerequisites = parts[5].split(",", Qt::SkipEmptyParts);  // Split prerequisites by comma

    return true;
}

// Check if the course has a specific prerequisite
bool Course::hasPrerequisite(const QString& prerequisite) const {
    return prerequisites.contains(prerequisite);
}
// New course management methods
bool Course::addCourse(const Course& course) {
    for (const Course& existingCourse : courseList) {
        if (existingCourse.getCourseID() == course.getCourseID()) {
            return false; // Duplicate course ID
        }
    }
    courseList.append(course);
    return true;
}

bool Course::editCourse(int courseID, const Course& updatedCourse) {
    for (Course& course : courseList) {
        if (course.getCourseID().toInt() == courseID) {
            course = updatedCourse;
            return true;
        }
    }
    return false; // Course ID not found
}

bool Course::removeCourse(int courseID) {
    for (int i = 0; i < courseList.size(); ++i) {
        if (courseList[i].getCourseID().toInt() == courseID) {
            courseList.removeAt(i);
            return true;
        }
    }
    return false; // Course ID not found
}

QVector<Course> Course::getAllCourses()  {
    return courseList;
}
