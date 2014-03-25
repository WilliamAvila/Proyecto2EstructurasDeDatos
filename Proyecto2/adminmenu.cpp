#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_pushButtonExit_clicked()
{
    this->close();
}

void AdminMenu::on_pushButtonAddConnection_clicked()
{
    cc.show();

}

void AdminMenu::on_pushButtonAddAirport_clicked()
{
    mw.show();

}

void AdminMenu::on_pushButtonDeleteAirport_clicked()
{
    da.show();

}

void AdminMenu::on_pushButtonDeleteConnection_clicked()
{
    dc.show();

}
