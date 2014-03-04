#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <mylabel.h>
#include <QWidget>
#include <dialogerror.h>
#include <dialogsucces.h>
#include "TinyXml/tinyxml.h"
#include <QPoint>
#include <string.h>
#include <iostream>
#include <QList>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QPainter *qp;
     QLabel *pin;
     void saveFlight();
     DialogError de;
     DialogSucces ds;
     TiXmlDocument doc;
     int pinX;
     int pinY;




private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
