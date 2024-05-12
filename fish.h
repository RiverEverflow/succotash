//
// Created by river on 24-5-11.
//

#ifndef LPHASE1_FISH_H
#define LPHASE1_FISH_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QDebug>

class fish : public QWidget{
    Q_OBJECT
    int greenBarLength = 0;
    QTimer *timer3 = new QTimer(this);
public:
    bool mousePressed = false;
    explicit fish(QWidget *parent = nullptr) : QWidget(parent) {
        connect(timer3, &QTimer::timeout, this, [=] {
            greenBarLength += 10; // 每次增加10像素
            if (greenBarLength >= width()) {
                timer3->stop();
            }
            update();
        });
    }
    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            mousePressed = false;
            timer3->stop();
            greenBarLength = 0; // 重置绿色条框的长度
        }
    }

    void paintOn(QPainter *painter,int x,int y,int sta) {
        if(sta==1){
            QPixmap pix(":/shake.png");
            painter->drawPixmap(x+40, y-240, pix);
            qDebug()<<mousePressed;
            if (mousePressed) {
                QPen pen(Qt::green); // 设置绿色的画笔
                pen.setWidth(10);
                painter->setPen(pen);
                painter->drawRect(x+40, y-240, greenBarLength, pix.height());
            }
        }
        qDebug()<<sta;
        if(sta==3){
            QPixmap pix(":/Fishingicon.png");
            painter->drawPixmap(x+40, y-240, pix);
            greenBarLength = 0;
        }
    }
};


#endif //LPHASE1_FISH_H
