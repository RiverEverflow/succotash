//
// Created by river on 24-5-9.
//

#ifndef LPHASE1_CHARACTER_H
#define LPHASE1_CHARACTER_H

#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPainter>

class character : public QLabel {
    Q_OBJECT
public:
    explicit character(QWidget* parent=nullptr) : QLabel(parent) {
        spriteSheet = QPixmap(":/Abigail.png");
        timer2 = new QTimer(this);

        connect(timer2, &QTimer::timeout, this, &character::changeFrame);
        timer2->start(100);
    }
    int direction = 3; // 1: down, 2: right, 3: up, 4: left,0: stop
    int lastDirection = 0;

public slots:
    void moveUp() {
        direction=3;
        animation->setStartValue(pos());
        animation->setEndValue(QPoint(x(), y() - speed));
        animation->setDuration(100);
        animation->start();
    }
    void moveDown() { direction=1;setGeometry(x(),y()+speed,64,128); }
    void moveLeft() { direction=4;startAnimation(QPoint(x() - speed, y()));}
    void moveRight() { direction=2;startAnimation(QPoint(x() + speed, y()));}

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        int frameWidth = spriteSheet.width() / frameCount;
        if(direction==0){
            QRect sourceRect1(0, (lastDirection-1)*32, 16, 32);
            painter.drawPixmap(rect(), spriteSheet, sourceRect1);
        }
        else{
        QRect sourceRect(currentFrame * frameWidth, (direction-1)*spriteSheet.height()/frameCount, frameWidth, spriteSheet.height()/frameCount);
        painter.drawPixmap(rect(), spriteSheet, sourceRect);}
    }


private:
    void changeFrame() {
        currentFrame = (currentFrame + 1) % frameCount;
        update();
    }
    void startAnimation(const QPoint &endPoint) {
        animation->setStartValue(pos());
        animation->setEndValue(endPoint);
        animation->start();
    }
    int speed = 20;
    QPixmap spriteSheet;
    int frameCount = 4; // 帧数
    int frameHeight = spriteSheet.height() / 4;
    int currentFrame=0;
    QTimer *timer2;
    QPropertyAnimation *animation=new QPropertyAnimation(this, "pos");
};


#endif //LPHASE1_CHARACTER_H
