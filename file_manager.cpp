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

QVector<Course> File_Manager::loadCourseData() {
    QVector<Course> courses;  // The vector to store the loaded courses
    QFile file(CourseFilePath); // Open the file (assuming CourseFilePath is defined)

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // If the file can't be opened, show a warning and return the empty courses vector
        qWarning() << "Error: Could not open the course file at path:" << CourseFilePath;
        return courses;
    }

    QTextStream in(&file);  // Stream for reading the file
    int lineCount = 0;  // To track the number of lines processed
    while (!in.atEnd()) {
        QString line = in.readLine();  // Read a line from the file
        lineCount++;

        // Assuming fromString() is implemented in Course class to deserialize a course object from a string
        Course course;
        if (course.fromString(line)) {  // If parsing is successful
            courses.append(course);  // Add the course to the vector
        } else {
            qWarning() << "Invalid course data at line" << lineCount << ":" << line;
        }
    }

    file.close();  // Close the file after reading

    qDebug() << "Successfully loaded" << courses.size() << "courses from the file:" << CourseFilePath;

    // Optionally, you can assign the loaded courses to a static member of the Course class if needed
    Course::courseList = courses;  // Store the loaded data in the static course list of the Course class

    return courses;  // Return the vector of loaded courses
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
    QString adminFilePath = "C:/Users/Merna/Desktop/Admins.txt";  // Corrected file path
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
    QVector<Event> events;  // The vector to store the loaded events
    QFile file(EventFilePath);  // Open the file (assuming EventFilePath is defined)

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // If the file can't be opened, show a warning and return the empty events vector
        qWarning() << "Error: Could not open the event file at path:" << EventFilePath;
        return events;
    }

    QTextStream in(&file);  // Stream for reading the file
    int lineCount = 0;  // To track the number of lines processed
    while (!in.atEnd()) {
        QString line = in.readLine();  // Read a line from the file
        lineCount++;

        // Assuming fromString() is implemented in Event class to deserialize an event object from a string
        Event event;
        if (Event::fromString(line, event)) {  // If parsing is successful
            events.append(event);  // Add the event to the vector
        } else {
            qWarning() << "Invalid event data at line" << lineCount << ":" << line;
        }
    }

    file.close();  // Close the file after reading

    qDebug() << "Successfully loaded" << events.size() << "events from the file:" << EventFilePath;

    // Optionally, you can assign the loaded events to a static member of the Event class if needed
    Event::eventList = events; // Store the loaded data in the static event list of the Event class

    return events;  // Return the vector of loaded events
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

