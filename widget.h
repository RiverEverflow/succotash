#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QtMultimedia/QMediaPlayer>
#include <QPainter>
#include "noplace.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    friend class noplace;
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGraphicsScene *scene = new QGraphicsScene(this);
    void paintEvent(QPaintEvent *event);
    Ui::Widget* getUi() const { return ui; }
    noplace *place1 = new noplace();
//    QPainter painter(this);
//    QMediaPlayer *music=new QMediaPlayer(this);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
