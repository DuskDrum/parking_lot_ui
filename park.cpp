#include"park.h"

car::car(int num, int time) {
    this->num = num;
    this->time = time;
}


Doublestack::Doublestack() {

}
bool Doublestack::isfull() {
    if (this->top1 + 1 == this->top2)//栈满
        return true;
    else
        return false;
}
int Doublestack::push(car a, bool b) {//a是要入栈的车,b是选择栈，true为停车场，false为临时栈
    if (this->top1 + 1 == this->top2)//栈满
        return -1;
    if (b) {
        this->stack[++top1] = a;
        return top1;
    }
    else
    {
        this->stack[--top2] = a;
        return top2;
    }
}
bool Doublestack::pop(car& a,bool b) {
    if (b) {
        if (top1 == -1) {
            return false;
        }
        a = this->stack[top1--];
        return true;
    }
    else {
        if (top2 == 10) {
            return false;
        }
        a = this->stack[top2++];
        return true;
    }
}
bool Doublestack::isfind(int n) {
    for (int i = 0; i <= this->top1; i++) {
        if (this->stack[i].num == n)
            return true;
    }
    return false;
}




//队列构造函数
Listqueue::Listqueue() {
    this->front = new node();
    this->rear = this->front;
}
//队列析构函数
Listqueue::~Listqueue() {
    node* k = this->front;
    node* j = this->front;
    while (k) {
        j = k;
        k = k->next;
        delete j;
    }
}
//入队
void Listqueue::enqueue(car a) {
    node* k = new node();
    k->val = a;
    k->next = NULL;
    this->rear->next = k;
    this->rear = k;
    this->length++;
    return;
}
bool Listqueue::dequeue(car& a) {
    if (this->front == this->rear) {
        //队空
        return false;
    }
    else
    {
        node* k = this->front->next;
        a = k->val;
        this->front->next = k->next;
        this->length--;
        if (this->rear == k)
            this->rear = this->front;
        delete k;//释放空间
        return true;
    }

}
bool Listqueue::find(int n) {//n是要查找的车牌号
    node* k = this->front->next;
    while (k) {
        if (k->val.num == n)
            return true;
        else {
            k = k->next;
        }
    }
    return false;
}




park::park() {//park构造函数

}

bool park::input(QChar x,int y,int z,QString& s){
        QChar k = x;//判断进出模式
        int a = y;
        int b = z;
        if (k == 'A') {//进车
            car one_car(a, b);//构造车信息
            this->arive(one_car,s);
            return true;
        }
        else if (k == 'D') {//离开
            car one_car(a, b);
            this->leave(one_car,s);
            return true;
        }
        else if(k == 'E'){//输入结束
            s = "input finish!";
            return false;
        }
        else {
            s = "input error!please try again";
            return true;
        }
}
void park::arive(car a,QString& s) {
    if (this->lot.isfind(a.num) || this->street.find(a.num)) {
        s = "You can't input ths same car number";
    }
    else {
        if (this->lot.isfull()) {//车满
            this->street.enqueue(a);
            s = QString("Your car is parked at number %1 ").arg(street.length) + QString("on the street");//停在street上
            //qDebug("停车场",street.length,"位");
        }
        else {
            s = QString("Your car is parked at number %1 ").arg(this->lot.push(a, true) + 1) + QString("in the parking lot");
        }
    }
}
void park::leave(car a,QString& s) {
    int duration2 = 0;
    int time = a.time;
    car one_car(-1, -1);
    if (!this->street.find(a.num)) {//street中没有目标车
        while (1) {
            if (!this->lot.pop(one_car, true))
                s = QString("there is no that car");
            if (one_car.num != a.num) {
                this->lot.push(one_car, false);//进入临时栈
            }
            else {//找到要离开的车
                duration2 = a.time - one_car.time;
                one_car.money += duration2 * 3;//
                s = QString("charge %1").arg(one_car.money) + QString("$");
                while (this->lot.pop(one_car, false))
                    this->lot.push(one_car, true);//临时栈车辆归位
                car another_car(-1, -1);
                if (this->street.dequeue(another_car)) {//街道车入场
                    int duration1 = a.time - another_car.time;
                    another_car.money += duration1 * 1;//在街道停车一小时1￥
                    this->lot.push(another_car, true);
                }
                break;
            }
        }
    }
    else {//在street中找车
        while (1) {
            if (this->street.dequeue(one_car)) {
                if (one_car.num == a.num) {
                    duration2 = a.time - one_car.time;
                    one_car.money += duration2 * 1;//在street停车一小时1￥
                    s = QString("charge%1").arg(one_car.money) + QString("$");
                }
                else {
                    this->street.enqueue(one_car);
                }
            }
        }
    }
}

info park::getinfo()
{
    this->ifo.lot_car_num = this->lot.top1+1;
    this->ifo.street_car_num = this->street.length;
    return this->ifo;
}
