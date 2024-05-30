#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ball.h"
#include "border.h"
#include <QMainWindow>
#include<QTimer>
#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void timerHit();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event) override;

    ball m_ball;
    border m_border;
    QTimer * m_timer;
};
#endif // MAINWINDOW_H






