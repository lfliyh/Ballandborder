#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *);


private:
    Ui::Widget *ui;
    bool move=false;
    int y=50;
    float t=0;
    int g=10;
    int max=50;
    float q=0.9;
};
#endif // WIDGET_H
