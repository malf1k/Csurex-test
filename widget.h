#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QFileDialog>

class QGraphicsScene;

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void LoadButtonClicked(); // реализацию функций следует писать в cpp файлах
    // ShowImage yне должна возвращать значение, разве что булевое, сигнализирующее об успешности выполнения
    /*QPixmap*/ void ShowImage(); // реализацию функций следует писать в cpp файлах

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString file_name;
    QPixmap imgs;
    QGraphicsScene *scene_for_view = nullptr;
    QGraphicsView * view = nullptr;
};
#endif // WIDGET_H
