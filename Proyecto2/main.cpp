#include "mainwindow.h"
#include "useradmin.h"
#include <QApplication>
#include <iostream>
#include <QIcon>
#include <TinyXml/tinyxml.h>
#include <grafo.h>
#include <connection.h>
#include <airport.h>
#include <list>
using namespace  std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserAdmin w;
    w.show();
    int x=4*4+4*4+4-4*4;
    cout<<x<<endl;
    a.setWindowIcon(QIcon("://imgs/digital-airline.jpg"));







    return a.exec();

}
