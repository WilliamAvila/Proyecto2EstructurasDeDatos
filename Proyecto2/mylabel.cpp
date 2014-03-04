#include "mylabel.h"

myLabel::myLabel(QWidget *parent) :
    QLabel(parent)
{

}

void myLabel::paintEvent(QPaintEvent *)
{
    doc= TiXmlDocument("Mis Vuelos.xml") ;

    QPainter painter(this);

  /*  painter.drawLine(10,10,100,100);
   painter.drawEllipse(100,100,50,50);*/

   doc.LoadFile();

  TiXmlNode *patr=doc.FirstChild();

int h,w;
TiXmlAttribute *atrW =patr->ToElement()->FirstAttribute();
TiXmlAttribute *atrH =patr->ToElement()->LastAttribute();

atrW->Next()->QueryIntValue(&w);
atrH->QueryIntValue(&h);

while(patr){
   int x,y;
   TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
   TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();

   atrX->Next()->QueryIntValue(&x);
   cout<<x<<endl;

   atrY->QueryIntValue(&y);
   cout<<y<<endl;
     painter.drawLine(x+10,y+25,w+10,h+25);

   patr=patr->NextSibling();
}

painter.drawEllipse(w+10-25,h+25-30,50,50);
}

void myLabel::DrawLabel(QPaintEvent *)
{

   QPixmap mypix(QSize(20,20));

   QPainter painter();



   label =new QLabel("",this);

   label->setPixmap(mypix);
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
   /* QPixmap qp=QPixmap(":/imgs/map-pin-md.png");

    QLabel *lb=new QLabel(this);

    lb->setPixmap(qp);
    lb->setGeometry(ev->x()-10,ev->y()-25,20,25);
    lb->setScaledContents(true);
    lb->raise();
    lb->show();*/
}
