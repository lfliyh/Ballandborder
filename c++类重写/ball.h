#ifndef BALL_H
#define BALL_H
#include<QRectF>

#include <QWidget>

class ball : public QWidget
{
    Q_OBJECT
public:
    explicit ball(QWidget *parent = nullptr);
    ball(int x, int y, int radius, int speedX = 0, int speedY = 0);

    void updatePosition();
    void checkCollision(const QRectF &border);
    void draw(QPainter &painter) const;
private:
    QPointF m_position;
    int m_radius;
    int m_speedX;
    int m_speedY;
    float s=0.9;
signals:
};

#endif // BALL_H
