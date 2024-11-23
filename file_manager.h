#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <QString>
#include <QVector>
#include "course.h"
#include "student.h"
#include "event.h"
#include "admin.h"
class File_Manager
{
public:
    //Constructor
    File_Manager();
    void loadAllData();  // New method to load all data
    // Course
    QVector<Course> loadCourseData(); //LOAD
    void saveCourseData(const QVector<Course>& courses); //SAVE
    //Admin
 QVector<Admin> loadAdminData();  // NEW FUNCTION
    // Student
    QVector<Student> loadStudentData(); //LOAD
    void saveStudentData(const QVector<Student>& students); //SAVE

    // Event
    QVector<Event> loadEventData(); //LOAD
    void saveEventData(const QVector<Event>& events); //SAVE

private:
    QString CourseFilePath; //FILE PATHS!!!!!
    QString StudentFilePath;
    QString EventFilePath;
    static bool dataLoaded;
};

#endif // FILE_MANAGER_H
