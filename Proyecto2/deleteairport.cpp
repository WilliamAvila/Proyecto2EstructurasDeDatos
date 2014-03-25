#include "deleteairport.h"
#include "ui_deleteairport.h"
#include "TinyXml/tinyxml.h"

DeleteAirport::DeleteAirport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAirport)
{
    ui->setupUi(this);
    doc=TiXmlDocument("Mis Vuelos.xml");
    this->setAirport();
}

DeleteAirport::~DeleteAirport()
{
    delete ui;
}

void DeleteAirport::delA(QString aeropuerto)
{
    doc.LoadFile();

   TiXmlNode *patr=doc.FirstChild();
   while(patr){

//       QString airport = QString::fromUtf8(patr->FirstChild()->Value());
//        if(ui->comboBox->itemText(ui->comboBox->currentIndex())==airport){
//
//            //doc.RemoveChild(patr);
//           break;
//        }

         cout<<patr->Value();

         patr=patr->NextSibling();
   }

}

void DeleteAirport::on_pushButton_clicked()
{

    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void DeleteAirport::on_pushButton_2_clicked()
{
    this->close();
}

void DeleteAirport::setAirport()
{
    doc.LoadFile();

   TiXmlNode *patr=doc.FirstChild();
   while(patr){
       QString airport = QString::fromUtf8(patr->Value());

       ui->comboBox->addItem(airport);

         patr=patr->NextSibling();
   }

}
