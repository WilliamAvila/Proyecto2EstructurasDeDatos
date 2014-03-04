#ifndef USERADMIN_H
#define USERADMIN_H
#include <mainwindow.h>
#include <QMainWindow>
#include <windowuser.h>

namespace Ui {
class UserAdmin;
}

class UserAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserAdmin(QWidget *parent = 0);
        MainWindow m;
       WindowUser wu;
    ~UserAdmin();

private slots:
    void on_pushButton_2_clicked();


    void on_pushButton_clicked();

private:
    Ui::UserAdmin *ui;

};

#endif // USERADMIN_H
