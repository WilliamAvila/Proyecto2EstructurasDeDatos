#ifndef CREATECONNECTION_H
#define CREATECONNECTION_H

#include <QDialog>
#include <QMessageBox>
#include<string.h>
#include<QLabel>
#include <QPixmap>
#include <mylabel.h>
#include<TinyXml/tinyxml.h>
using namespace std;
namespace Ui {
class CreateConnection;
}

class CreateConnection : public QDialog
{
    Q_OBJECT

public:
    explicit CreateConnection(QWidget *parent = 0);
    ~CreateConnection();
    TiXmlDocument doc;
    TiXmlDocument con;
    myLabel *draw;
    void showPts();
    void setAirport();
    void readCon();
    void writeCon();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateConnection *ui;
};

#endif // CREATECONNECTION_H
