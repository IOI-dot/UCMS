#ifndef ADMIN_EVENT_MANAGEMENT_H
#define ADMIN_EVENT_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class admin_event_management;
}

class admin_event_management : public QDialog
{
    Q_OBJECT

public:
    explicit admin_event_management(QWidget *parent = nullptr);
    ~admin_event_management();

private:
    Ui::admin_event_management *ui;
};

#endif // ADMIN_EVENT_MANAGEMENT_H
