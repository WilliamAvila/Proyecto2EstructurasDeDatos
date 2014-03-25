#ifndef DELETECONNECTION_H
#define DELETECONNECTION_H

#include <QDialog>
#include "TinyXml/tinyxml.h"
namespace Ui {
class DeleteConnection;
}

class DeleteConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConnection(QWidget *parent = 0);
    ~DeleteConnection();
    void setAirport();
    TiXmlDocument doc;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DeleteConnection *ui;
};

#endif // DELETECONNECTION_H
