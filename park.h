#ifndef PARK_H
#define PARK_H

#include<iostream>
#include<QString>
#include<QChar>
#include<QDebug>

#define parksize 10

using namespace std;
class car {
public:
    int num;//车牌号
    int time;//time
    int money = 0;

    car() :num(-1), time(-1) {

    };
    car(int num,int time);
};
class info{
public:
    int lot_car_num;
    int street_car_num;
    info() :lot_car_num(0), street_car_num(0) {

    };
    info(int a,int b){
        lot_car_num = a;
        street_car_num = b;
    }
};
class Doublestack {//双向栈
public:
    car stack[parksize];
    int top1 = -1;
    int top2 = 10;

    Doublestack();
    int push(car a, bool b);
    bool pop(car& a,bool b);//pop失败返回false
    bool isfull();
    bool isfind(int n);

};

class node {
public:
    car val;
    node* next;

    node():val(car(0,0)),next(NULL){
    }
};

class Listqueue {
public:
    node* front;//头指针
    node* rear;//尾指针
    int length = 0;

    Listqueue();
    ~Listqueue();
    void enqueue(car a);
    bool dequeue(car& a);
    bool find(int n);
};

class park {
public:
    park();
    bool input(QChar x,int y,int z,QString& s);//输入一组三个值
    void arive(car a,QString& s);//车辆到达打印所在位置
    void leave(car a,QString& s);//车辆离开打印应缴金额，两种情况，从lot和从street离开
    info getinfo();
private:
    Doublestack lot;
    Listqueue street;
    info ifo;//用于给绘图事件传递数据
};



#endif // PARK_H
