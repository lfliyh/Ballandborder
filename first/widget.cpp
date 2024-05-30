#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<qtimer>
#include<qdebug.h>
#include<QMouseEvent>
#include<qpushbutton.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(300,600);
    QTimer *timer1 = new QTimer(this);
    connect(timer1,&QTimer::timeout,[=]()
    {
        y=y+10;
        qDebug()<<y;
        update();
        if(y==450)
        {
            max=max+50;

            timer1->stop();

            QTimer *timer2 = new QTimer(this);
            timer2->start(20);
            connect(timer2,&QTimer::timeout,[=]()
                    {
                        y=y-10;
                        qDebug()<<y;
                        update();
                        if(y==max)
                        {
                            timer2->stop();
                            timer1->start();
                        }
                        });
            if(max>=450)
                {
                    timer2->stop();
                    timer1->stop();
                }



        }
    });
    QPushButton * btn1 = new QPushButton(this);
    btn1->setText("开始");
    btn1->move(100,525);
    btn1->resize(100,50);




    connect(btn1,&QPushButton::clicked,[=](){
        timer1->start(20);});






}
void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    // 画线
    QPen pen1(width());

    painter.setPen(pen1);
    painter.drawRect(100,0,100,500);

    //设置画笔
    QPen pen (QColor(255,0,0));
    //让画家使用笔
    painter.setPen(pen);

    //画刷
    QBrush brush(QColor(255,0,0));
    painter.setBrush(brush);


    // 画圆

    painter.drawEllipse(QPoint(150,y),50,50);
    painter.setRenderHint(QPainter::Antialiasing);


}
void Widget::timerEvent(QTimerEvent *)
{
    y=y+1;
    this->update();
}
Widget::~Widget()
{
    delete ui;
}
