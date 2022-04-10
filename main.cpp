#include "dialog.h"
#include <QGraphicsScene>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
//    QGraphicsScene *scene = new QGraphicsScene;
//    scene->setSceneRect(QRectF(0,0,720,720));
//    car *cars = new car;
//    cars->setPos(cars->x,cars->y);
//    scene->addItem(cars);
//    QGraphicsView *view = new QGraphicsView;
//    view->setScene(scene);
//    view->resize(720,720);
//    view->setBackgroundBrush(QPixmap(":/image/map.png"));
//    view->show();
//    return a.exec();
}
