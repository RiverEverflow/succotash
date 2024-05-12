//
// Created by river on 24-5-6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_noplace.h" resolved

#include "noplace.h"
#include "ui_noplace.h"
#include "widget.h"
#include <QKeyEvent>
#include <QDebug>
#include "fish.h"


noplace::noplace(QWidget *parent) :
        QWidget(parent), ui(new Ui::noplace), timer1(new QTimer(this)), currentImageIndex(0), Aris(new character(this)){
    ui->setupUi(this);
    images.append(QPixmap(":/Screenshot 2024-05-09 173739.png"));
    images.append(QPixmap(":/Screenshot 2024-05-09 173757.png"));
    images.append(QPixmap(":/Screenshot 2024-05-09 173814.png"));
    connect(timer1, &QTimer::timeout, this, &noplace::changeImage);
    timer1->start(300);
    Aris->setGeometry(759, 580, 64, 128);
    Aris->show();
    fish1 = new fish(this);
    timer2 = new QTimer(this);
}

void noplace::paintEvent(QPaintEvent *event) {
    QPainter painter01(this);
    QPixmap pix(":/Screenshot 2024-05-05 232546.png");
    QPixmap pix2(":/Screenshot 2024-05-09 171104.png");
    QPixmap pix3(":/Abigail.png");
    QPixmap setpix = pix.scaled(this->width(), pix.height(), Qt::KeepAspectRatio);
    painter01.drawPixmap(0, 0, images[currentImageIndex]);
    painter01.drawPixmap(585, this->height()-pix.height(), setpix);
    fish1->paintOn(&painter01,Aris->x(),Aris->y(),currentstate);
    if(showText){
        painter01.drawText(this->rect(), Qt::AlignCenter, text);
    }
}

void noplace::changeImage() {
    currentImageIndex = (currentImageIndex + 1) % images.size();
    update();
}

void noplace::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W:
            Aris->moveUp();
            break;
        case Qt::Key_A:
            Aris->moveLeft();
            break;
        case Qt::Key_S:
            Aris->moveDown();
            break;
        case Qt::Key_D:
            Aris->moveRight();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void noplace::keyReleaseEvent(QKeyEvent *event) {
    Aris->lastDirection = Aris->direction;
    Aris->direction = 0;
}

void noplace::mousePressEvent(QMouseEvent *event) {
    if(state::hang == currentstate){
        currentstate = cast;
           fish1->mousePressed = true;
    }
    if(state::wait == currentstate){
        currentstate = pull;
    }
}

void noplace::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if(state::cast == currentstate){
            timer2->start(3000);
            currentstate = wait;
            connect(timer2, &QTimer::timeout, this, [=] {
                showText = true;
                timer2->stop();
            } )  ;
        }
        fish1->mousePressed = false;
        currentstate = wait;
    }
}

noplace::~noplace() {
    delete ui;
    delete timer1;
    delete Aris;
}
