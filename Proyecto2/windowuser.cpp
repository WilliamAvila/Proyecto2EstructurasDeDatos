#include "windowuser.h"
#include "ui_windowuser.h"

WindowUser::WindowUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowUser)
{
    ui->setupUi(this);
    doc= TiXmlDocument("Mis Vuelos.xml") ;
     mc= TiXmlDocument("Mis Conexiones.xml") ;


    //connect(this->draw,SIGNAL(MousePos()),this,SLOT(Mouse_Current_Pos()));
    this->setAirport();
     this->ReadXML();





}

WindowUser::~WindowUser()
{
    delete ui;
}

void WindowUser::ReadXML()
{


        doc.LoadFile();

       TiXmlNode *patr=doc.FirstChild();


    int i=0;
    while(patr){
        int x,y;


        TiXmlAttribute *atrX =patr->ToElement()->FirstAttribute();
        TiXmlAttribute *atrY =patr->ToElement()->LastAttribute();


        atrX->Next()->QueryIntValue(&x);
        //cout<<x<<endl;

        atrY->QueryIntValue(&y);
        //cout<<y<<endl;


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
        i++;
    }



}

void WindowUser::setAirport()
{
    doc.LoadFile();

   TiXmlNode *patr=doc.FirstChild();
   while(patr){
       QString airport = QString::fromUtf8(patr->Value());


        graph.insertAirport(airport);
       ui->comboBoxPaisDestino->addItem(airport);
        ui->PaisOrigen->addItem(airport);
         patr=patr->NextSibling();
   }






}

void WindowUser::AddConnections()
{
     mc.LoadFile();

     TiXmlNode *patr=mc.FirstChild();
     while(patr){

         QString inicio = QString::fromUtf8(patr->ToElement()->Attribute("Origen"));
         QString destino = QString::fromUtf8(patr->ToElement()->Attribute("Destino"));
         double precio = atof(patr->ToElement()->Attribute("Precio"));


            graph.insertConnection(inicio,destino,precio);

           patr=patr->NextSibling();
     }

}

void WindowUser::on_pushButton_clicked()
{

     draw =new myLabel(ui->label);
     draw->setGeometry(0,0,811,601);
     draw->raise();
     draw->show();

}

void WindowUser::Mouse_Current_Pos()
{
    //ui->labelAirport->setText(QString("X= %1 , Y= %2").arg(draw->x).arg(draw->y));
}

void WindowUser::on_pushButton_3_clicked()
{

    this->close();
    ui->lineEdit->setText("$0.00");

}

void WindowUser::on_pushButton_4_clicked()
{

    draw->setVisible(false);
    ui->lineEdit->clear();
    ui->label_6->clear();

}

void WindowUser::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
     this->AddConnections();

    double minis;

    //minis=graph.MinimoAirp("hn","sp");

    //graph.MinimoAdj(ui->PaisOrigen->itemText(ui->PaisOrigen->currentIndex()));
   // double ap=graph.MinimoAdj(ui->PaisOrigen->itemText(ui->PaisOrigen->currentIndex()));


    //graph.MinimoAirp(ui->PaisOrigen->itemText(ui->PaisOrigen->currentIndex())," ");
    cout<<graph.cont<<endl;


    int indexOrigin=graph.recuperar(ui->PaisOrigen->itemText(ui->PaisOrigen->currentIndex()));
    int indexDest=graph.recuperar(ui->comboBoxPaisDestino->itemText(ui->comboBoxPaisDestino->currentIndex()));
            int ap=graph.MatrizAdj(indexOrigin,indexDest);



       ui->textEdit->insertPlainText(ui->PaisOrigen->itemText(ui->PaisOrigen->currentIndex()));
        ui->textEdit->insertPlainText("\n");

       ui->textEdit->insertPlainText(ui->comboBoxPaisDestino->itemText(ui->comboBoxPaisDestino->currentIndex()));



        if(ap>=10000)
            ui->label_6->setText("No Hay Conexion");
        else{
       QString valueAsString = QString::number(ap);

         ui->lineEdit->setText(valueAsString );
          ui->label_6->clear();
        }



}
