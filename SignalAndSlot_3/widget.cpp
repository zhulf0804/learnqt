#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("abc");

    connect(&b1, &QPushButton::pressed, this, &Widget::close);
    // &b1：信号发出者, 指针类型
    // &QPushButton::pressed: 处理的信号, 发送者的类名::信号名字
    // this: 信号接收者
    // &Widget::close: 槽函数，信号处理函数  &接收的类名::槽函数的名字


     // 自定义槽，普通函数的用法
     // Qt5:任意的成员函数，普通全局函数，静态函数
     // 槽函数需要和信号一致（参数，返回值）
     // 由于信号没有返回值，所以槽函数一定没有返回值
    connect(b2, &QPushButton::released, this, &Widget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    this->setWindowTitle("boss");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    //w.show();
    //connect(&b3, &QPushButton::released, this, &Widget::changeWin);


    // 函数指针
    void (SubWidget::*funSignal)() = &SubWidget::mySignal;

    connect(&w, funSignal, this, &Widget::dealSub);

    void (SubWidget::*testSignal)(int, QString) = &SubWidget::mySignal;
    connect(&w, testSignal, this, &Widget::dealSlot);

    // Lambda表达式， 匿名函数
    // C++11增加的新特性，项目文件: CONFIG += C++11
    // Qt配合信号一起使用，非常方便

    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150, 150);
    int a = 10, b = 1;
    /*
    connect(b4, &QPushButton::released,
            // = : 把外部所有局部变量、类中所有成员以值传递方式传递
            // this: 类中所有成员以值传递方式传递
            // &: 把外部所有局部变量，引用符号
            [=]()mutable{
                b4->setText("123");
                qDebug() << "hello";
                a = 11;
                qDebug() << a << b;
            });*/

    connect(b4, &QPushButton::released,
            // = : 把外部所有局部变量、类中所有成员以值传递方式传递
            // this: 类中所有成员以值传递方式传递
            // &: 把外部所有局部变量，引用符号
            [=]()mutable{

                //qDebug() << isCheck;
                w.show();
                this->hide();

            });

    resize(400, 300);
    qDebug() << a << b;
}

void Widget::dealSlot(int a, QString str){
    qDebug() << a << str << endl;
}

void Widget::changeWin(){
    w.show();
    this->hide();
}

void Widget::mySlot(){
    b2->setText("123");
}

void Widget::dealSub(){
    w.hide();
    this->show();
}

Widget::~Widget()
{

}
