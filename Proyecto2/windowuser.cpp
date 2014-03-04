#include "windowuser.h"
#include "ui_windowuser.h"

WindowUser::WindowUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowUser)
{
    ui->setupUi(this);
 doc= TiXmlDocument("Mis Vuelos.xml") ;





}

WindowUser::~WindowUser()
{
    delete ui;
}

void WindowUser::ReadXML()
{


        doc.LoadFile();

       TiXmlNode *patr=doc.FirstChild();



    while(patr){
        int x,y;
        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();

        atrX->Next()->QueryIntValue(&x);
        cout<<x<<endl;

        atrY->QueryIntValue(&y);
        cout<<y<<endl;




//        cout<<patr->ToElement()->Attribute("Codigo")<<endl;
//        cout<<patr->ToElement()->Attribute("X")<<endl;
//        cout<<patr->ToElement()->Attribute("Y")<<endl;



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

void WindowUser::on_pushButton_clicked()
{
    draw =new myLabel(this);
    draw->setGeometry(0,0,811,601);
    draw->raise();
     draw->show();
    this->ReadXML();
}
