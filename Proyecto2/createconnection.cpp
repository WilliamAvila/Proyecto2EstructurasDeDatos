    #include "createconnection.h"
#include "ui_createconnection.h"

CreateConnection::CreateConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateConnection)
{
    ui->setupUi(this);
    doc=TiXmlDocument("Mis Vuelos.xml");
    this->showPts();
    con=TiXmlDocument("Mis Conexiones.xml");
    this->setAirport();
       this->readCon();

}

CreateConnection::~CreateConnection()
{
    delete ui;
}

void CreateConnection::on_pushButton_clicked()
{
    QMessageBox qm;

    if(ui->comboBox->itemText(ui->comboBox->currentIndex())==""
            || ui->comboBox_2->itemText(ui->comboBox_2->currentIndex())==""
            || ui->lineEdit->text()=="" ||ui->lineEdit->text()==0){
        qm.setText("Ingrese todos los datos       ");
         qm.setStandardButtons(QMessageBox::Ok);
         qm.exec();
         if(QMessageBox::Ok)
             qm.close();
    }else if(ui->comboBox->itemText(ui->comboBox->currentIndex())==
                 ui->comboBox_2->itemText(ui->comboBox_2->currentIndex())){
        qm.setText("Ingrese un Aeropuerto Diferente      ");
         qm.setStandardButtons(QMessageBox::Ok);
         qm.exec();
         if(QMessageBox::Ok)
             qm.close();

    }else{
        this->writeCon();




    }
}

void CreateConnection::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->comboBox->itemText(0);
    ui->comboBox_2->itemText(0);

    this->close();

}

void CreateConnection::showPts()
{
    doc.LoadFile();

     TiXmlNode *patr=doc.FirstChild();



    while(patr){
        int x,y;


        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();


        atrX->Next()->QueryIntValue(&x);

        atrY->QueryIntValue(&y);


          QLabel *pin =new QLabel(this);
          QPixmap qp=QPixmap(":/imgs/map-pin-md.png");
          pin->setPixmap(qp);
          pin->setGeometry(x,y,20,25);
          pin->setScaledContents(true);
          pin->raise();
          pin->show();
        patr=patr->NextSibling();

    }

}

void CreateConnection::setAirport()
{
    doc.LoadFile();

   TiXmlNode *patr=doc.FirstChild();
   while(patr){
       QString airport = QString::fromUtf8(patr->Value());

       ui->comboBox->addItem(airport);
        ui->comboBox_2->addItem(airport);
         patr=patr->NextSibling();
   }

}

void CreateConnection::readCon()
{
    draw=new myLabel(ui->label);
    draw->setGeometry(0,0,811,601);
    draw->raise();
    draw->show();

}

void CreateConnection::writeCon()
{
    QMessageBox qm;
    bool comp=false;
    double prc = ui->lineEdit->text().toDouble(&comp);
    if(!comp){
        qm.setText("Ingrese los datos Correctamente");
         qm.setStandardButtons(QMessageBox::Ok);
         qm.exec();
         if(QMessageBox::Ok)
             qm.close();
         return;
     }
    QString ori = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString dest = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());


       con.LoadFile();

       TiXmlElement *element=new TiXmlElement("Conexion");
       element->SetAttribute("Origen",ori.toStdString().c_str());
       element->SetAttribute("Destino",dest.toStdString().c_str());
       element->SetDoubleAttribute("Precio",prc);

       //text->LinkEndChild(point);
       con.LinkEndChild(element);
       con.SaveFile();

       qm.setText("Conexion Creada Exitosamente       ");
       qm.setStandardButtons(QMessageBox::Ok);
       qm.exec();
      ui->lineEdit->clear();
       if(QMessageBox::Ok)
           qm.close();


}
