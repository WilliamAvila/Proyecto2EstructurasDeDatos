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

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::saveFlight()
{
    string el=ui->lineEditCod->text().toUtf8().constData();
    cout<<el<<endl;

    string tx =ui->lineEditCiudad->text().toStdString();
    cout<<tx<<endl;
       doc.LoadFile();

       TiXmlElement *element=new TiXmlElement(tx.c_str());
       element->SetAttribute("Codigo",el.c_str());
       element->SetAttribute("X",pinX);
       element->SetAttribute("Y",pinY);

       //text->LinkEndChild(point);
       doc.LinkEndChild(element);
       doc.SaveFile();

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.background();
    painter.drawLine(10,10,100,100);


}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    pinX=ev->x()-10;
    pinY=ev->y()-35;

       QPixmap qp=QPixmap(":/imgs/map-pin-md.png");
        pin->setPixmap(qp);
        pin->setGeometry(pinX,pinY,20,25);
        pin->setScaledContents(true);
        pin->raise();
        pin->show();





}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEditCod->text()==""||ui->lineEditCiudad->text()==""
            ||pinX==0||pinY==0){
            de.show();

    }else{
        this->saveFlight();
        ds.show();

    }

}
