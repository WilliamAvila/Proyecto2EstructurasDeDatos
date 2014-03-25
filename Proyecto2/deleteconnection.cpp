#include "deleteconnection.h"
#include "ui_deleteconnection.h"

DeleteConnection::DeleteConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConnection)
{
    ui->setupUi(this);
    doc=TiXmlDocument("Mis Vuelos.xml");
    this->setAirport();

}

DeleteConnection::~DeleteConnection()
{
    delete ui;
}

void DeleteConnection::on_pushButton_2_clicked()
{
    this->close();
}

void DeleteConnection::on_pushButton_clicked()
{

}

void DeleteConnection::setAirport()
{
    doc.LoadFile();

   TiXmlNode *patr=doc.FirstChild();
   while(patr){
       QString airport = QString::fromUtf8(patr->Value());

       ui->comboBox->addItem(airport);

         patr=patr->NextSibling();
   }

}
