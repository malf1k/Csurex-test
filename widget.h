#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QFileDialog>

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void LoadButtonClicked()
    {
        QString file_name = QFileDialog::getOpenFileName(this);
        imgs.load(file_name);

    }

    QPixmap ShowImage()
    {
        QPixmap imgs(file_name);
        return imgs;
    }
public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString file_name;
    QPixmap imgs;

};
#endif // WIDGET_H
