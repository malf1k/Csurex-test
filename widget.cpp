#include "widget.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QMainWindow>
#include <QFileDialog>



void Widget::LoadButtonClicked()
{
    /*QString file_name = QFileDialog::getOpenFileName(this); // ваша переменная file_name
     * определена в классе, поэтому внутри функции вам не нужно создавать ноую переменную*/
    file_name = QFileDialog::getOpenFileName(this);
    imgs.load(file_name);

}

/*QPixmap*/ void Widget::ShowImage()
{
    /* QPixmap imgs(file_name); //imgs уже был загружен в память в функции LoadButtonClicked()
     * В Этой фнкцие его не нужно заного создавать. Вам нужно использовать тот который уже загружен*/

    //return imgs; // возвращаемый тип void

    // Далее в этой функции нужно создать или перезаписать объекту класса QGraphicsPixmapItem
    // Для того, что бы это сделать, необходимо сделать ваши QGraphicsScene и QGraphicsView членами класса

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(imgs); // создаем тут QGraphicsPixmapItem, и не забываем очистить scen перед закрытием ПО
    scene_for_view->addItem(item);
    view->setScene(scene_for_view);

}

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



    /*QGraphicsPixmapItem *item = new QGraphicsPixmapItem(imgs);   // в этом месте вам не нужен Item */
    /*scene->addItem(item);*/
    view = new QGraphicsView(this);
    scene_for_view = new QGraphicsScene(view);
    view->setScene(scene_for_view);
    body->addWidget(view, 5, 1, 1, 1);
    setLayout(body);


}



Widget::~Widget()
{
    scene_for_view->clear();



}

