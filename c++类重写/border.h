#ifndef BORDER_H
#define BORDER_H

#include <QWidget>

class border : public QWidget
{
    Q_OBJECT
public:
    explicit border(QWidget *parent = nullptr);
    border(const QRectF &rect) : m_rect(rect) {}

    QRectF rect() const { return m_rect; }

private:
    QRectF m_rect;

signals:
};

#endif // BORDER_H
