         #ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();

signals:
    //信号没有返回值，可以有参数
    //信号就是函数的声明，只需声明，无需定义
    void mySignal();
    void mySignal(int, QString);

public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
