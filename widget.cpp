#include "widget.h"
#include "./ui_widget.h"
#include <QtMultimedia/QMediaPlayer>
#include <QPainter>
#include "noplace.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Screenshot 2024-05-04 104437.png"));
    connect(ui->startButton, &QPushButton::clicked, [=](){
       this->hide();
       place1->show();
    });
    connect(ui->exitButton, &QPushButton::clicked, [=](){
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter02(this);
    QPixmap pix(":/Screenshot 2024-05-04 104437.png");
    QPixmap pixed=pix.scaled(this->width(), this->height(),Qt::KeepAspectRatio);
    painter02.fillRect(this->rect(), pixed);
}
