#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mySlot();

private:
    QPushButton b1;
    QPushButton *b2;
};

#endif // WIDGET_H
