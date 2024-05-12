//
// Created by river on 24-5-6.
//

#ifndef LPHASE1_NOPLACE_H
#define LPHASE1_NOPLACE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "character.h"
#include "fish.h"

#include <QUrl>


QT_BEGIN_NAMESPACE
namespace Ui { class noplace; }
QT_END_NAMESPACE

class noplace : public QWidget {
Q_OBJECT

public:
    character *Aris;
    fish *fish1;
    explicit noplace(QWidget *parent = nullptr);
    enum state {hang,cast,wait,pull};
    state currentstate = hang;

    ~noplace() override;
    void paintEvent(QPaintEvent *event) override;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void changeImage();

private:
    Ui::noplace *ui;
    QTimer *timer1,*timer2;
    QVector<QPixmap> images;
    int currentImageIndex;
    bool showText = false;
    QString text="上钩了";
};


#endif //LPHASE1_NOPLACE_H
