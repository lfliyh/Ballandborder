#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_ball(200, 50, 50,0,16), m_border(QRectF(0, 0, 400, 400)),m_timer(new QTimer(this))
{
    ui->setupUi(this);

    resize(400,400);
    // m_timer->setInterval(100);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::timerHit);
    m_timer->start(10);
}
void MainWindow::timerHit() {
    m_ball.updatePosition();
    m_ball.checkCollision(m_border.rect());
    update(); // 触发paintEvent
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    m_ball.draw(painter);
    // 绘制边界的代码
}
MainWindow::~MainWindow()
{
    delete ui;
}
