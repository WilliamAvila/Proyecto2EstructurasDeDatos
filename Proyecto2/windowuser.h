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
    //QLabel *pin;
    myLabel *draw;
    void ReadXML();
    QList<QPoint>mypoints;

private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowUser *ui;
};

#endif // WINDOWUSER_H
