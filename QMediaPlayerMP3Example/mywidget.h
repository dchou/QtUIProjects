#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QDebug>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_sliderProgress_sliderMoved(int position);
    void on_sliderVolume_sliderMoved(int position);
    void on_buttonStart_clicked();
    void on_buttonStop_clicked();
    void on_positionChanged(qint64 position);
    void on_durationChannged(qint64 position);

private:
    Ui::MyWidget *ui;
    QMediaPlayer* player;
};

#endif // MYWIDGET_H
