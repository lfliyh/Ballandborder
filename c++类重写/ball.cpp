#include "ball.h"
#include<QPainter>

ball::ball(QWidget *parent)
    : QWidget{parent}
{}
ball::ball(int x, int y, int radius, int speedX, int speedY)
    : m_position(x, y), m_radius(radius), m_speedX(speedX), m_speedY(speedY){}

void ball::updatePosition() {
    m_position.rx() += m_speedX;
    m_position.ry() += m_speedY;
}

void ball::checkCollision(const QRectF &border) {
    // 碰撞检测和速度更新
    if (m_position.x() - m_radius <= border.left() || m_position.x() + m_radius >= border.right()) {
        m_speedX = -m_speedX;
        m_speedY =m_speedY*0.5;
    }
    if (m_position.y() - m_radius <= border.top() || m_position.y() + m_radius >= border.bottom()) {
        m_speedY = -m_speedY;
        m_speedY =m_speedY*0.5;

    }
}

void ball::draw(QPainter &painter) const {
    painter.setPen(Qt::NoPen);
    painter.setBrush( Qt::red);
    painter.drawEllipse(m_position, m_radius, m_radius);
}
