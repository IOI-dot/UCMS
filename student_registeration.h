#ifndef STUDENT_REGISTERATION_H
#define STUDENT_REGISTERATION_H

#include <QDialog>

namespace Ui {
class Student_Registeration;
}

class Student_Registeration : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Registeration(QWidget *parent = nullptr);
    ~Student_Registeration();

private:
    Ui::Student_Registeration *ui;
};

#endif // STUDENT_REGISTERATION_H
