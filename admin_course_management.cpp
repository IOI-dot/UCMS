#include "admin_course_management.h"
#include "ui_admin_course_management.h"
#include "course.h"
#include "file_manager.h"
#include "admin_homepage.h"  // Include the header for the admin homepage
#include <QMessageBox>
admin_course_management::admin_course_management(Admin* admin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_course_management),
    currentAdmin(admin)
// Store the passed Admin pointer
{
    ui->setupUi(this);

    // Initialize File_Manager instance
    File_Manager fileManager;

    // Load courses from file
    QVector<Course> loadedCourses = fileManager.loadCourseData();

    // Store the courses in the static course list of the Course class
    Course::courseList = loadedCourses;

    // Connect the back-to-home button to its slot
    connect(ui->BackToHome, &QPushButton::clicked, this, &admin_course_management::on_BackToHome_clicked);
}

admin_course_management::~admin_course_management() {
    delete ui;
}

// Add a course
void admin_course_management::on_ADD_clicked() {
    QString id = ui->CRNADD->text();
    QString name = ui->NAMEADD->text();
    QString department = ui->DEPADD->text();
    QString instructor = ui->INSADD->text();
    QString schedule = ui->SCHADD->text();
    QVector<QString> prerequisites = ui->lineEdit_5->text().split(",", Qt::SkipEmptyParts);

    // Check if all fields are filled
    if (id.isEmpty() || name.isEmpty() || department.isEmpty() || instructor.isEmpty() || schedule.isEmpty() || prerequisites.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all the fields.");
        return;  // Exit the function if any field is empty
    }

    // Create the new course
    Course newCourse(id, name, department, instructor, schedule, prerequisites);

    // Try to add the course using the static addCourse method
    if (!Course::addCourse(newCourse)) {
        QMessageBox::warning(this, "Error", "Course ID already exists!");
        return;
    }

    // Refresh the UI
    refreshUI();

    // Clear input fields
    ui->CRNADD->clear();
    ui->NAMEADD->clear();
    ui->DEPADD->clear();
    ui->INSADD->clear();
    ui->SCHADD->clear();
    ui->lineEdit_5->clear();

    QMessageBox::information(this, "Success", "Course added successfully!");
}

// Edit a course
void admin_course_management::on_EDIT_clicked() {
    QString id = ui->CRNADD_2->text();  // Get the CRN entered by the user

    // Check if CRN field is empty
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a CRN to edit.");
        return;  // Exit the function if CRN is empty
    }

    bool courseFound = false;

    // Search for the course with the entered CRN
    for (Course& course : Course::courseList) {
        if (course.getCourseID() == id) {
            courseFound = true;  // Course exists, so we can edit it

            // Check if any fields are left empty
            if (ui->NAMEADD_2->text().isEmpty() || ui->DEPADD_2->text().isEmpty() ||
                ui->INSADD_2->text().isEmpty() || ui->SCHADD_2->text().isEmpty() || ui->lineEdit_6->text().isEmpty()) {
                QMessageBox::warning(this, "Error", "Please fill in all fields before saving.");
                return;  // Exit the function if any field is empty
            }

            // Update the course with new values
            course.setName(ui->NAMEADD_2->text());
            course.setDepartment(ui->DEPADD_2->text());
            course.setInstructor(ui->INSADD_2->text());
            course.setSchedule(ui->SCHADD_2->text());
            course.setPrerequisites(ui->lineEdit_6->text().split(",", Qt::SkipEmptyParts));

            // Refresh the UI
            refreshUI();

            // Clear input fields
            ui->CRNADD_2->clear();
            ui->NAMEADD_2->clear();
            ui->DEPADD_2->clear();
            ui->INSADD_2->clear();
            ui->SCHADD_2->clear();
            ui->lineEdit_6->clear();
            QMessageBox::information(this, "Success", "Course edited successfully!");
            return;  // Exit the function once the course is updated
        }
    }

    // If the course with the entered CRN is not found
    if (!courseFound) {
        QMessageBox::warning(this, "Error", "Course ID not found! Please enter a valid CRN.");
    }
}

void admin_course_management::on_DelteBottun_clicked() {
    QString id = ui->DELETEDIT->text().trimmed();  // Get and trim the input

    // Check if the input is empty
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid Course ID.");
        return;
    }

    // Check if the course ID exists in the course list
    bool courseFound = false;
    for (int i = 0; i < Course::courseList.size(); ++i) {
        if (Course::courseList[i].getCourseID() == id) {
            courseFound = true;  // Mark as found
            // Convert the course ID (QString) to an integer for deletion
            int courseID = id.toInt();

            // Try to remove the course using the static removeCourse method
            if (Course::removeCourse(courseID)) {
                // Refresh the UI
                refreshUI();

                // Clear input fields
                ui->DELETEDIT->clear();
                QMessageBox::information(this, "Success", "Course deleted successfully!");
            } else {
                // If the course couldn't be removed
                QMessageBox::warning(this, "Error", "Failed to delete the course. Please try again.");
            }
            break;  // Exit loop after deleting the course
        }
    }

    // If course ID is not found
    if (!courseFound) {
        QMessageBox::warning(this, "Error", "Course ID not found! Please enter a valid CRN.");
    }
}


void admin_course_management::on_BackToHome_clicked() {
    // Hide the current event registration dialog
    this->close();

    // Show the existing student homepage dialog
    if (parentWidget()) {
        parentWidget()->show();  // This will show the parent window (which is the student homepage)
    }
}

void admin_course_management::refreshUI() {
    // The refreshUI method now displays the courses from Course::courseList directly
    // You can further populate UI components with course information if needed
}
