#include "dialogsucces.h"
#include "ui_dialogsucces.h"

DialogSucces::DialogSucces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSucces)
{
    ui->setupUi(this);
}

DialogSucces::~DialogSucces()
{
    delete ui;
}

void DialogSucces::on_pushButton_clicked()
{
    this->close();

}
