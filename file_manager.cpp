#include "file_manager.h" //HEADER
#include <QFile> //FOR OPENNIGN AND READING FILES
#include <QTextStream> //FOR SAVING STRINGS ON FILES
#include <QDebug> // DEBUGGING ANY BAD THING
#include "student.h"
#include "course.h"
#include "event.h"
File_Manager::File_Manager() {//NEED MORE CONSTRUCTORS
    CourseFilePath="C:/Users/Merna/Desktop/Courses.txt";
    StudentFilePath="C:/Users/Merna/Desktop/Students.txt";
    EventFilePath="C:/Users/Merna/Desktop/Events.txt";
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
QVector<Admin> File_Manager::loadAdminData() {
    QVector<Admin> admins;
    QString adminFilePath = "C/Users/Merna/Desktop/Admins.txt";  // Corrected file path
    QFile file(adminFilePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open the file for reading:" << adminFilePath;
        return admins;  // Return an empty vector if the file cannot be opened
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(", ");
        if (parts.size() < 3) {
            qWarning() << "Invalid admin data format:" << line;
            continue; // Skip invalid lines
        }

        // Extract fields (Remove the prefix like "Username: ", "Password: ", etc.)
        QString username = parts[0].mid(QString("Username: ").length());
        QString password = parts[1].mid(QString("Password: ").length());
        QString email = parts[2].mid(QString("Email: ").length());

        qDebug() << "Loaded admin data:" << username << password << email;

        // Create an Admin object and append to the vector
        Admin admin(username, password, email);
        admins.append(admin);
    }

    file.close();

    Admin::loadAdminDataFromFile(admins); // Populate the static vector in Admin

    return admins;  // Return the loaded admins (optional, you can remove this return)
}

QVector<Student> File_Manager::loadStudentData() {
    QVector<Student> students;
    QFile file(StudentFilePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open the file for reading:" << StudentFilePath;
        return students;  // Return an empty vector if the file cannot be opened
    }

    QTextStream in(&file);
    int lineCount = 0;  // To track how many lines we read
    while (!in.atEnd()) {
        QString line = in.readLine();
        lineCount++;

        QStringList parts = line.split(", ");
        if (parts.size() < 4) {  // Ensure there are enough parts for valid student data
            qWarning() << "Invalid student data format at line" << lineCount << ":" << line;
            continue; // Skip invalid lines
        }

        // Extract fields (Remove the prefix like "Username: ", "Password: ", etc.)
        QString username = parts[0].mid(QString("Username: ").length());
        QString password = parts[1].mid(QString("Password: ").length());
        QString email = parts[2].mid(QString("Email: ").length());
        QString studentID = parts[3].mid(QString("Student ID: ").length());
        QString academic = parts[4].mid(QString("Academic Status: ").length());

        qDebug() << "Loaded student data from line" << lineCount << ":" << username << password << email << studentID<<academic;

        // Create a Student object and append to the vector
        Student student(username, password, email, studentID, academic);
        students.append(student);
    }

    file.close();

    // After reading all the students, confirm how many students were loaded
    qDebug() << "Successfully loaded" << students.size() << "students from the file:" << StudentFilePath;

    // Optionally, store the loaded students into the static student list
    Student::studentList = students;  // Store the loaded data in the static vector of Student class

    return students;  // Return the loaded students (optional, you can remove this return)
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
QVector<Event> File_Manager::loadEventData() {
    QVector<Event> events;
    QFile file(EventFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Error, could not open event file!";
        return events;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        Event event;
        if (Event::fromString(line, event)) {  // Pass the line and the event object
            events.append(event);
        } else {
            qWarning() << "Failed to parse event data:" << line;  // Debugging message
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

