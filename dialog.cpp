#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(720,720);
    QGraphicsScene *scene = new QGraphicsScene(this);
    QLabel *top = new QLabel(this);
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    top->setText(QString("input:"));
    top->setFont(font);
    top->setStyleSheet("color: white");
    top->setGeometry(110,60,327,27);
    carEdit = new QLineEdit(this);
    carEdit->setPlaceholderText(QString("number"));
    carEdit->setGeometry(263,60,50,27);
    timeEdit = new QLineEdit(this);
    timeEdit->setPlaceholderText(QString("time"));
    timeEdit->setGeometry(323,60,50,27);
    operEdit = new QLineEdit(this);
    operEdit->setPlaceholderText(QString("operate"));
    operEdit->setGeometry(383,60,50,27);
    topBtn = new QPushButton(QString("finish"),this);
    topBtn->setGeometry(523,55,60,37);
    topBtn->setStyleSheet("QPushButton{background-color:rgb(254,252,242);\
                                      color: green;   border-radius: 10px;  border: 2px groove gray;\
                                      border-style: outset; font-size:20px;font-weight: bold;}"
                                     "QPushButton:hover{background-color:green; color: white;}"
                                    "QPushButton:pressed{background-color:green;\
                                                     border-style: inset;}"
                                                     );
    msg = new MassageBox;
    connect(topBtn,SIGNAL(clicked()),this,SLOT(getInput()));
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::paintEvent(QPaintEvent *)
{
    this->ifo = this->mypark.getinfo();
    QPainter painter (this);
    QPixmap pix;
    pix.load(":/image/map.png");
    painter.drawPixmap(0,0,pix);
    for(int i = 0;i<this->ifo.lot_car_num;i++){
        pix.load(":/image/car.png");
        pix = pix.scaled(62,42);
        painter.drawPixmap(lot_start-interval*i,lot_y,pix);
    }
    //685,317
    for(int i = 0;i<11&&i<this->ifo.street_car_num;i++){
        pix.load(":/image/car.png");
        pix = pix.scaled(62,42);
        painter.drawPixmap(street_start-interval*i,street_y1,pix);
    }
    for(int i = 11;i<this->ifo.street_car_num;i++){
        pix.load(":/image/car.png");
        pix = pix.scaled(62,42);
        painter.drawPixmap(street_start-interval*(i-11),street_y2,pix);
    }
}

void Dialog::getInput()
{
    inputs.num = carEdit->text().toInt();
    inputs.oper = operEdit->text().at(0);
    inputs.time = timeEdit->text().toInt();
    mypark.input(inputs.oper,inputs.num,inputs.time,this->text);
    qDebug()<<this->text;
    msg->SetText(text);
    msg->show();
}

