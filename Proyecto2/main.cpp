#include "mainwindow.h"
#include "useradmin.h"
#include <QApplication>
#include <iostream>
#include <QIcon>
#include <TinyXml/tinyxml.h>
using namespace  std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserAdmin w;
    w.show();
    int x=4*4+4*4+4-4*4;
    cout<<x<<endl;
    a.setWindowIcon(QIcon(":/imgs/img-world-map.png"));


    return a.exec();

}
