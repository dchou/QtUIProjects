// C++ Qt 130 - Playing videos with QMediaPlayer
//   https://www.youtube.com/watch?v=tGKmQy-VBX0
#include "mydialog.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DC MyDialog w;
    //DC w.show();

    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget *vw = new QVideoWidget;

    player->setVideoOutput(vw);
    //OK player->setMedia(QUrl::fromLocalFile("/Users/dchou/Documents/1561794360745259.mp4"));
    player->setMedia(QUrl::fromLocalFile("/Users/dchou/Music/iTunes/iTunes Media/Podcasts/CNN 10 (video)/CNN10 - 5_23_19.mp4"));

    vw->setGeometry(100,100,300,400);
    vw->show();

    player->play();
    qDebug() << player->state();

    return a.exec();
}
