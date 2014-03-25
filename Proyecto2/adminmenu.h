#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include <createconnection.h>
#include <mainwindow.h>
#include <deleteairport.h>
#include <deleteconnection.h>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = 0);
    ~AdminMenu();
    MainWindow mw;
    CreateConnection cc;
    DeleteConnection dc;
    DeleteAirport da;

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonAddConnection_clicked();

    void on_pushButtonAddAirport_clicked();

    void on_pushButtonDeleteAirport_clicked();

    void on_pushButtonDeleteConnection_clicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
