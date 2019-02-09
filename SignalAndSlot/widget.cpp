#include "widget.h"
#include <QPushButton>

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


}

void Widget::mySlot(){
    b2->setText("123");
}

Widget::~Widget()
{

}
