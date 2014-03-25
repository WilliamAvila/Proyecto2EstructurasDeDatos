#ifndef DELETEAIRPORT_H
#define DELETEAIRPORT_H

#include <QDialog>
#include  "TinyXml/tinyxml.h"
#include <iostream>

using namespace std;

namespace Ui {
class DeleteAirport;
}

class DeleteAirport : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAirport(QWidget *parent = 0);
    ~DeleteAirport();
    TiXmlDocument doc;
    void delA(QString aeropuerto);
    void setAirport();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DeleteAirport *ui;
};

#endif // DELETEAIRPORT_H
