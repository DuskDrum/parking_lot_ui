#ifndef DIALOG_H
#define DIALOG_H

#include"park.h"
#include <QDialog>
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include<QFont>
#include<QLineEdit>
#include<QPushButton>
#include<QGraphicsScene>
#include<QString>
#include<QChar>
#include<QDebug>
#include "massagebox.h"

using namespace std;
struct data{
    QChar oper;
    int num;
    int time;
};

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void paintEvent(QPaintEvent *);
public slots:
    void getInput();

private:
    Ui::Dialog *ui;
    park mypark;
    struct data inputs;
    int interval = 66;
    int lot_y = 395;
    int lot_start = 618;
    int street_y1 = 270;
    int street_y2 = 480;
    int street_start = 652;
    QLineEdit *carEdit;
    QLineEdit *timeEdit;
    QLineEdit *operEdit;
    QPushButton *topBtn;
    MassageBox *msg;//消息提示框
    QString text;
    info ifo;
};
#endif // DIALOG_H
