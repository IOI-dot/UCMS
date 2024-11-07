#ifndef ADMIN_HOMEPAGE_H
#define ADMIN_HOMEPAGE_H

#include <QDialog>

namespace Ui {
class admin_homepage;
}

class admin_homepage : public QDialog
{
    Q_OBJECT

public:
    explicit admin_homepage(QWidget *parent = nullptr);
    ~admin_homepage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin_homepage *ui;
};

#endif // ADMIN_HOMEPAGE_H
