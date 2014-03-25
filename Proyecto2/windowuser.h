#ifndef WINDOWUSER_H
#define WINDOWUSER_H
#include <TinyXml/tinyxml.h>
#include <QMainWindow>
#include <iostream>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include<QWidget>
#include <mylabel.h>
#include <QList>
#include <vector>
#include <grafo.h>
#include <connection.h>
#include <airport.h>

using namespace std;

namespace Ui {
class WindowUser;
}

class WindowUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowUser(QWidget *parent = 0);
    ~WindowUser();
    TiXmlDocument doc;
    TiXmlDocument mc;
    //QLabel *pin;
    myLabel *draw;
    void ReadXML();
    QList<QPoint>mypoints;
    void setAirport();
    void AddConnections();
    Grafo graph;

private slots:
    void on_pushButton_clicked();
    void Mouse_Current_Pos();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WindowUser *ui;
};

#endif // WINDOWUSER_H
