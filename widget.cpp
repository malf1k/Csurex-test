#include "widget.h"
#include "QLabel"
#include "QGridLayout"
#include "QPushButton"
#include "QGraphicsPixmapItem"
#include "QMainWindow"

#include <QPixmap>
#include <QMainWindow>
#include <QFileDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* body = new QGridLayout(this);

    QPushButton* open = new QPushButton("Open");
    QPushButton* save = new QPushButton("Save");
    QPushButton* show = new QPushButton("Show");

    QLabel* label = new QLabel(this);


    open->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    open->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    open->setFixedSize(75, 30);
    body->addWidget(open, 1, 1, 1, 1);

    save->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    save->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    save->setFixedSize(75, 30);
    body->addWidget(save, 2, 1, 1, 1);

    show->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    show->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    show->setFixedSize(75, 30);
    body->addWidget(show, 3, 1, 1, 1);

    body->addWidget(label);

    label->setPixmap(imgs);

    connect(open, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));
    connect(show, SIGNAL(clicked()), this, SLOT(ShowImage()));


    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(imgs);
    scene->addItem(item);
    QGraphicsView *view = new QGraphicsView(scene, this);

    body->addWidget(view, 5, 1, 1, 1);
    setLayout(body);


}



Widget::~Widget()
{




}

