#include "massagebox.h"

MassageBox::MassageBox(QWidget *parent):QDialog(parent)
{
    this->setFixedSize(600,100);
    label =new QLabel(this);
    label->setGeometry(0,40,600,30);
//    font.setPointSize(70);
    label->setStyleSheet("font-size:20px;color:rgb(254,107,0)");
//    pa.setColor(qRgb(254,107,0));
//    lable.setPalette(pa);
}

void MassageBox::SetText(QString s)
{
    this->label->setText(s);
}
