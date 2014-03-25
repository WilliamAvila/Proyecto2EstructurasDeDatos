#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>
#include <adminmenu.h>
#include <QMessageBox>

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = 0);
    ~LoginAdmin();
    AdminMenu am;

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginAdmin *ui;
};

#endif // LOGINADMIN_H
