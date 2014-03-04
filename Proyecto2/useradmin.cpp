#include "useradmin.h"
#include "ui_useradmin.h"

UserAdmin::UserAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAdmin)
{
    ui->setupUi(this);
}

UserAdmin::~UserAdmin()
{
    delete ui;
}

void UserAdmin::on_pushButton_2_clicked()
{
    this->close();
    m.show();



}

void UserAdmin::on_pushButton_clicked()
{
    this->close();
    wu.show();

}
