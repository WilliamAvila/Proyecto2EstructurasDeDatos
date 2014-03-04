#ifndef DIALOGSUCCES_H
#define DIALOGSUCCES_H

#include <QDialog>

namespace Ui {
class DialogSucces;
}

class DialogSucces : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSucces(QWidget *parent = 0);
    ~DialogSucces();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogSucces *ui;
};

#endif // DIALOGSUCCES_H
