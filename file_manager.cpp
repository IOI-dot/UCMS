/* #include "file_manager.h" //HEADER
#include <QFile> //FOR OPENNIGN AND READING FILES
#include <QTextStream> //FOR SAVING STRINGS ON FILES
#include <QDebug> // DEBUGGING ANY BAD THING
#include "student.h"
File_Manager::File_Manager(const QString& cPath, const QString& sPath, const QString& ePath) {//NEED MORE CONSTRUCTORS
    CourseFilePath=cPath;
    StudentFilePath=sPath;
    EventFilePath=ePath;
}
QVector<Course> File_Manager::loadCourseData(){
    QVector<Course> courses;
    QFile file(CourseFilePath); //OPEN THE FILE GIVEN
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { //DEBUGGING METHOD
        qWarning() << "error,could not open course file!!";
        return courses;
    }

    QTextStream in(&file);  //STORE THE DATA AS AN OBJECT OF TEXT
    while (!in.atEnd()) {
        QString line = in.readLine();
        Course course;
        if (course.fromString(line)) {  // MAKE THE COURSE FROMSTRING SO WE CAN PUT THE DATA IN THE CLASS
            courses.append(course);
        }
    }
    file.close();
    return courses;
}
void File_Manager::saveCourseData(const QVector<Course>& courses) {
    QFile file(CourseFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "error,could not open course file!!";
        return;
    }

    QTextStream out(&file);
    for (const Course& course : courses) {
        out << course.toString() << "\n";  // MAKE SURE YOU HAVE A TOSTRING IN THE CLASS
    }
    file.close();
}
QVector<Student> File_Manager::loadStudentData() {
    QVector<Student> students;
    QFile file(StudentFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "error, could not open student file!!";
        return students;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        Student student;
        if (Student::fromString(line, student)) {  // Ensure valid Student is loaded
            students.append(student);
        }
    }
    file.close();
    return students;
}
void File_Manager::saveStudentData(const QVector<Student>& students) {
    QFile file(StudentFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "error, could not open student file!!";
        return;
    }

    QTextStream out(&file);
    for (const Student& student : students) {
        out << student.toString() << "\n";  // Ensure consistent format
    }
    file.close();
}
// Load Event Data
QVector<Event> File_Manager::loadEventData() {
    QVector<Event> events;
    QFile file(EventFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "error,could not open course file!!";
        return events;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        Event event;
        if (event.fromString(line)) {  // SAME!!!!!!!!!!
            events.append(event);
        }
    }
    file.close();
    return events;
}



void File_Manager::saveEventData(const QVector<Event>& events) {
    QFile file(EventFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "EROR";
        return;
    }

    QTextStream out(&file);
    for (const Event& event : events) {
        out << event.toString() << "\n";  // NICE
    }
    file.close();
}
*/
