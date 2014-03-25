#include "mylabel.h"

myLabel::myLabel(QWidget *parent) :
    QLabel(parent)
{

}

void myLabel::paintEvent(QPaintEvent *)
{
        doc= TiXmlDocument("Mis Vuelos.xml") ;
        con= TiXmlDocument("Mis Conexiones.xml") ;

        QPainter painter(this);


        doc.LoadFile();
        con.LoadFile();


         TiXmlNode *patrC=con.FirstChild();


        while(patrC){
            int x,y , x1,y1;

            TiXmlAttribute *origin =patrC->ToElement()->FirstAttribute();


            TiXmlAttribute *dest =origin->Next();





             TiXmlNode *patr=doc.FirstChild();
                while(patr){
                     string val1=origin->Value();
                     string val2=patr->Value();
                     string val3=dest->Value();


                    if(val1==val2){
                        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
                        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();

                        atrX->Next()->QueryIntValue(&x);




                        atrY->QueryIntValue(&y);

                    }

                    if(val3==val2){
                        TiXmlAttribute *atrX1 =patr->ToElement()->FirstAttribute();
                        TiXmlAttribute *atrY1 =patr->ToElement()->LastAttribute();

                        atrX1->Next()->QueryIntValue(&x1);


                        atrY1->QueryIntValue(&y1);


                    }

                    patr=patr->NextSibling();
                }

                /*cout<<x<<endl;
                cout<<y<<endl;
                cout<<x1<<endl;
                cout<<y1<<endl;*/

             painter.drawLine(x-20,y-5,x1-20,y1-5);

           patrC=patrC->NextSibling();
        }


//        painter.drawEllipse(0,0,50,50);
//        painter.drawLine(0,0,50,50);
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

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{   this->x=ev->x();
    this->y=ev->y();

    emit MousePos();
}
