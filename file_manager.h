#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <QString>
#include <QVector>
#include "course.h"
#include "Student.h"
#include "event.h"

class File_Manager
{
public:
    //Constructor
    File_Manager(const QString& coursePath, const QString& studentPath, const QString& eventPath);
    // Course
    QVector<Course> loadCourseData(); //LOAD
    void saveCourseData(const QVector<Course>& courses); //SAVE

    // Student
    QVector<Student> loadStudentData(); //LOAD
    void saveStudentData(const QVector<Student>& students); //SAVE

    // Event
    QVector<Event> loadEventData(); //LOAD
    void saveEventData(const QVector<Event>& events); //SAVE

private:
    QString courseFilePath; //FILE PATHS!!!!!
    QString studentFilePath;
    QString eventFilePath;
};

#endif // FILE_MANAGER_H
