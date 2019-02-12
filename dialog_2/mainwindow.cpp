#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
       QMenuBar *mBar = menuBar();

       QMenu *menu = mBar->addMenu("对话框");

       QAction *p1 = menu->addAction("模态对话框");

       connect(p1, &QAction::triggered,
               [=](){
                    QDialog dlg;
                    dlg.exec();
                    qDebug() << "i am motai dialog";
                });
       QAction *p2 = menu->addAction("非模态对话框");

       connect(p2, &QAction::triggered,
               [=](){
// 成员
//                     dlg.show();

 // 局部变量，动态分配空间,程序结束的时候才释放
 //                     QDialog *p = new QDialog(this);
 //                     p->show();

// 局部变量，动态分配空间,不指定父对象，关闭的方式设置!
                        QDialog *p = new QDialog;
                        p->setAttribute(Qt::WA_DeleteOnClose);
                        p->show();

                        qDebug() << "i am fei motai dialog";
                 });

       QAction *p3 = menu->addAction("关于对话框");

       connect(p3, &QAction::triggered,
               [=](){
                    QMessageBox::about(this, "about", "关于qt");
                });

       QAction *p4 = menu->addAction("问题对话框");

       connect(p4, &QAction::triggered,
               [=](){
                   int ret = QMessageBox::question(this, "question", "Are you ok?",

                                                   QMessageBox::Ok,

                                                   QMessageBox::Retry,

                                                   QMessageBox::Cancel
                                                   );
                   switch (ret) {
                   case QMessageBox::Yes:
                       qDebug() << "i am ok";
                       break;
                   case QMessageBox::No:
                       qDebug() << "i am bad";
                       break;
                   default:
                       break;
                   }
                });

       QAction *p5 = menu->addAction("文件对话框");

       connect(p5, &QAction::triggered,
               [=](){

                 QString path = QFileDialog::getOpenFileName(this,
                                                                "open",
                                                                "../",
                                                                "source(*.cpp *.h);;"
                                                                "Images (*.png *.xpm *.jpg);;"
                                                                "Text files (*.txt);;"
                                                                "all(*.*)");

                  qDebug() << path;
       });





}

MainWindow::~MainWindow()
{

}
