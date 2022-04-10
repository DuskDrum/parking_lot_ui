#ifndef MASSAGEBOX_H
#define MASSAGEBOX_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QPalette>
#include <QString>

class MassageBox : public QDialog
{
    Q_OBJECT
public:
    MassageBox(QWidget* parent=0);
    void SetText(QString s);
private:
        QLabel *label;
        QFont font;
        QPalette pa;
};

#endif // MASSAGEBOX_H
