#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pin=new QLabel(ui->label);
    pinX=0;
    pinY=0;
    doc=TiXmlDocument("Mis Vuelos.xml");
    this->showPoints();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::saveFlight()
{
    string el=ui->lineEditCod->text().toUtf8().constData();


    string tx =ui->lineEditCiudad->text().toStdString();

       doc.LoadFile();

       TiXmlElement *element=new TiXmlElement(tx.c_str());
       element->SetAttribute("Codigo",el.c_str());
       element->SetAttribute("X",pinX);
       element->SetAttribute("Y",pinY);

       //text->LinkEndChild(point);
       doc.LinkEndChild(element);
       doc.SaveFile();

}

void MainWindow::showPoints()
{
    doc.LoadFile();

     TiXmlNode *patr=doc.FirstChild();



    while(patr){
        int x,y;
        cout<<patr->Value()<<endl;

        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();


        atrX->Next()->QueryIntValue(&x);

        atrY->QueryIntValue(&y);


          QLabel *pin =new QLabel(this);
          QPixmap qp=QPixmap(":/imgs/map-pin-md.png");
          pin->setPixmap(qp);
          pin->setGeometry(x,y+10,20,25);
          pin->setScaledContents(true);
          pin->raise();
          pin->show();
        patr=patr->NextSibling();

    }

}

bool MainWindow::ClickPoint(QMouseEvent *ev)
{
    bool spot =false;

    doc.LoadFile();

     TiXmlNode *patr=doc.FirstChild();



    while(patr){
        int x,y;

        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();


        atrX->Next()->QueryIntValue(&x);

        atrY->QueryIntValue(&y);

        /*if((((x1>= x)&& (x1<= x+20)) || ((x1+20 >= x)&& (x1+20 <= x+20))) &&
               (((y1 >= y) && (y1 <= y+20)) || ((y1+20 >= y) && (y1+20 <= y+20))))*/


         patr=patr->NextSibling();

    }
    return spot;

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    /*QPainter painter(this);
    painter.background();
    painter.drawLine(10,10,100,100);
*/

}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{


        if(ev->x()>30&&ev->y()>30&&ev->x()<811&&ev->y()<601){

            pinX=ev->x()-10;
            pinY=ev->y()-35;

       QPixmap qp=QPixmap(":/imgs/map-pin-md.png");
        pin->setPixmap(qp);
        pin->setGeometry(pinX-30,pinY-30,20,25);
        pin->setScaledContents(true);
        pin->raise();
        pin->show();
    }




}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEditCod->text()==""||ui->lineEditCiudad->text()==""
            ||pinX==0||pinY==0){
            de.show();

    }else{
        this->saveFlight();
        ds.show();
        ui->lineEditCiudad->clear();
        ui->lineEditCod->clear();

        QLabel *lb=new QLabel(this);
        QPixmap qp=QPixmap(":/imgs/map-pin-md.png");
        lb->setPixmap(qp);
         lb->setGeometry(pinX,pinY+10,20,25);
         lb->setScaledContents(true);
         lb->raise();
         lb->show();

    }

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEditCiudad->clear();
    ui->lineEditCod->clear();
    this->close();
}
