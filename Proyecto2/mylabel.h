#ifndef MYLABEL_H
#define MYLABEL_H
#include <QMouseEvent>
#include <QLabel>
#include <QtGui>
#include <QtCore>
#include <QPixmap>
#include <QPainter>
#include <QSize>
#include <QPoint>
#include <QList>
#include <TinyXml/tinyxml.h>
#include <iostream>

using namespace std;

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);
    QList <QPoint> puntos;
    void setListQPoint(QList <QPoint> pts);
    QPainter *painter;
    TiXmlDocument doc;
signals:

public slots:


protected:
    void paintEvent(QPaintEvent *);
    void DrawLabel(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

 private:
    QLabel *label;

};

#endif // MYLABEL_H
