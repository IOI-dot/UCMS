#include "file_manager.h" //HEADER
#include <QFile> //FOR OPENNIGN AND READING FILES
#include <QTextStream> //FOR SAVING STRINGS ON FILES
#include <QDebug> // DEBUGGING ANY BAD THING
File_Manager::File_Manager(const QString& coursePath, const QString& studentPath, const QString& eventPath) {//NEED MORE CONSTRUCTORS
    courseFilePath=coursePath;
    studentFilePath=studentPath;
    eventFilePath=eventPath;
}
QVector<Course> File_Manager::loadCourseData(){
    QVector<Course> courses;
    QFile file(courseFilePath); //OPEN THE FILE GIVEN
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
    QFile file(courseFilePath);
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
    QFile file(studentFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "error,could not open course file!!";
        return students;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        Student student;
        if (student.fromString(line)) {  // SAME AS BEFORE
            students.append(student);
        }
    }
    file.close();
    return students;
}
void File_Manager::saveStudentData(const QVector<Student>& students) {
    QFile file(studentFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "error,could not open course file!!";
        return;
    }

    QTextStream out(&file);
    for (const Student& student : students) {
        out << student.toString() << "\n";  // SAME
    }
    file.close();
}

// Load Event Data
QVector<Event> File_Manager::loadEventData() {
    QVector<Event> events;
    QFile file(eventFilePath);
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
    QFile file(eventFilePath);
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
