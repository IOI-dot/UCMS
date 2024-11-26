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
// In File_Manager.cpp
bool File_Manager::dataLoaded = false;

void File_Manager::loadAllData() {
    if (dataLoaded) {
        qDebug() << "Data already loaded. Skipping reloading.";
        return;
    }

    qDebug() << "Loading all data from files...";
    loadAdminData();   // Loads and populates the Admin's static list
    loadStudentData(); // Loads and populates the Student's static list
    loadCourseData();  // Loads and populates the Course's static list
    loadEventData();   // Loads and populates the Event's static list
    dataLoaded = true;
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
        return students;
    }

    QTextStream in(&file);
    int lineCount = 0;  // To track how many lines we read
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();  // Trim any unnecessary whitespace
        lineCount++;

        // Split the line into parts by commas, but only for the first 4 fields
        QStringList parts = line.split(",", Qt::SkipEmptyParts);

        // Ensure there are at least 5 parts (username, email, student ID, academic status, and courses)
        if (parts.size() < 5) {
            qWarning() << "Invalid student data format at line" << lineCount << ":" << line;
            continue; // Skip invalid lines
        }

        // Extract fields (remove the prefixes like "Username: ", "Email: ", etc.)
        QString username = parts[0].mid(QString("Username: ").length()).trimmed();
        QString email = parts[1].mid(QString("Email: ").length()).trimmed();
        QString studentID = parts[2].mid(QString("Student ID: ").length()).trimmed();
        QString academic = parts[3].mid(QString("Academic Status: ").length()).trimmed();

        // Ensure essential data is not empty
        if (username.isEmpty() || studentID.isEmpty() || email.isEmpty() || academic.isEmpty()) {
            qWarning() << "Missing essential data at line" << lineCount << ":" << line;
            continue; // Skip invalid lines
        }

        // **Handling the Courses part**:
        QString coursesString = line.mid(line.indexOf("Registered Courses: ") + QString("Registered Courses: ").length()).trimmed();

        // Extract courses string before "Registered Events" begins
        int eventsIndex = line.indexOf("Registered Events:");
        if (eventsIndex != -1) {
            coursesString = coursesString.mid(0, eventsIndex - line.indexOf("Registered Courses: ") - QString("Registered Courses: ").length()).trimmed();
        }

        // Clean up the courses string
        if (coursesString.startsWith("[") && coursesString.endsWith("]")) {
            coursesString = coursesString.mid(1, coursesString.length() - 2);  // Remove the surrounding brackets
        }
        // Clean up the courses string (remove brackets without regex)
        if (!coursesString.isEmpty() && coursesString[0] == '[') {
            coursesString.remove(0, 1);  // Remove the first character (open bracket)
        }

            coursesString.chop(1);  // Remove the last character (close bracket)


        // Remove any unwanted characters (e.g., trailing commas)
        coursesString.remove(',');  // Remove commas
        coursesString = coursesString.trimmed();  // Trim any extra spaces
        coursesString.replace(" ,", "");  // Remove any leftover space before commas
        coursesString.remove(']');

        // Split courses by pipe '|', ensuring to trim spaces
        QStringList courseList = coursesString.split("|", Qt::SkipEmptyParts);

        // Clean up the individual courses and add them to a QVector
        QVector<QString> registeredCourses;
        for (const QString& course : courseList) {
            QString trimmedCourse = course.trimmed();
            if (!trimmedCourse.isEmpty()) {
                registeredCourses.append(trimmedCourse);
            }
        }

        // **Handling the Registered Events part**:
        // Extract the portion after "Registered Events:" and trim it
        QString eventsString = line.mid(line.indexOf("Registered Events: ") + QString("Registered Events: ").length()).trimmed();

        // Check if there is a "Completed Prerequisites:" section and stop before it
        int prerequisitesIndex = line.indexOf("Completed Prerequisites:");
        if (prerequisitesIndex != -1) {
            eventsString = eventsString.left(prerequisitesIndex - line.indexOf("Registered Events: ") - QString("Registered Events: ").length()).trimmed();
        }

        // Clean up the events string
        if (eventsString.startsWith("[") && eventsString.endsWith("]")) {
            eventsString = eventsString.mid(1, eventsString.length() - 2);  // Remove the surrounding brackets
        }

        // Handle cases where multiple "Registered Events" sections might be present
        int repeatedEventsIndex = eventsString.indexOf("Registered Events:");
        if (repeatedEventsIndex != -1) {
            eventsString = eventsString.left(repeatedEventsIndex).trimmed();  // Remove any subsequent "Registered Events:" parts
        }

        // Remove any unwanted parts like extra commas and spaces
        eventsString = eventsString.trimmed();
        eventsString.replace(" ,", "");  // Remove any leftover space before commas
        eventsString.chop(1);
        eventsString.chop(1);
        if (!eventsString.isEmpty() && eventsString[0] == '[') {
            eventsString.remove(0, 1);  // Remove the first character (open bracket)
        }
        // Split events by pipe '|', ensuring to trim spaces
        QStringList eventList = eventsString.split("|", Qt::SkipEmptyParts);


        // Clean up the individual events and add them to a QVector
        QVector<QString> registeredEvents;
        for (const QString& event : eventList) {
            QString trimmedEvent = event.trimmed();
            if (!trimmedEvent.isEmpty()) {
                registeredEvents.append(trimmedEvent);
            }
        }

        // Debug: Show cleaned-up courses and events
        qDebug() << "Final Registered Courses:" << registeredCourses.join(", ");
        qDebug() << "Final Registered Events:" << registeredEvents.join(", ");

        // Create the Student object and set the courses and events
        Student student(username, email, studentID, academic);
        student.setRegisteredCourses(registeredCourses);  // Set the parsed courses
        student.setRegisteredEvents(registeredEvents);    // Set the parsed events
        students.append(student);
        QString prerequisitesString = line.mid(line.indexOf("Completed Prerequisites: ") + QString("Completed Prerequisites: ").length()).trimmed();

        // Clean up the prerequisites string (remove surrounding brackets)
        if (prerequisitesString.startsWith("[") && prerequisitesString.endsWith("]")) {
            prerequisitesString = prerequisitesString.mid(1, prerequisitesString.length() - 2);  // Remove surrounding brackets
        }

        // Remove any unwanted characters
        prerequisitesString = prerequisitesString.trimmed();
        prerequisitesString.replace(" ,", "");  // Remove any leftover space before commas

        // Split prerequisites by pipe '|', ensuring to trim spaces
        QStringList prerequisiteList = prerequisitesString.split("|", Qt::SkipEmptyParts);
        // Clean up the individual prerequisites and add them to a QVector
        QVector<QString> completedPrerequisites;
        for (const QString& prerequisite : prerequisiteList) {
            QString trimmedPrerequisite = prerequisite.trimmed();
            if (!trimmedPrerequisite.isEmpty()) {
                completedPrerequisites.append(trimmedPrerequisite);
            }
        }
        // Now set the completed prerequisites for the student
        student.setCompletedPrerequisites(completedPrerequisites);
        qDebug() << "Completed prerequisites set for student:" << completedPrerequisites.join(", ");

    }

    file.close();

    qDebug() << "Successfully loaded" << students.size() << "students from the file:" << StudentFilePath;

    // Optionally, store the loaded students into the static student list
    Student::studentList = students;

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
        out << student.toString() << "\n";  // Ensure consistent format with registered courses
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

