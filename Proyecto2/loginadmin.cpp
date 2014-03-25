#include "loginadmin.h"
#include "ui_loginadmin.h"

LoginAdmin::LoginAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
   ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

void LoginAdmin::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="admin" && ui->lineEdit_2->text()=="pass"){
        this->close();
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        am.show();
    }
    else{
        QMessageBox *msg = new QMessageBox(QMessageBox::Information, "Incorrect username or password!", "Datos Incorrectos", QMessageBox::Ok, this, Qt::Popup);
        msg->setDefaultButton(QMessageBox::Ok);
        msg->exec();

    }

}
