#ifndef EVENT_MANAGEMENT_H
#define EVENT_MANAGEMENT_H

#include <QDialog>
#include <QVector>
#include <QString>
#include "event.h"
#include "file_manager.h"
#include "ui_admin_event_management.h"

class admin_event_management : public QDialog {
    Q_OBJECT

public:
    explicit admin_event_management(QWidget *parent = nullptr);
    ~admin_event_management();

private slots:
    void on_ADD_clicked();   // Slot for the ADD button
    void on_EDIT_clicked();  // Slot for the EDIT button
    void on_DELETE_clicked();  // Slot for the DELETE button

private:
    void refreshUI();   // Method to refresh the UI and display the updated events

    Ui::admin_event_management *ui;
};

#endif // EVENT_MANAGEMENT_H
