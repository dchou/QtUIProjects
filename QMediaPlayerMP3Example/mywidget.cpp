// C++ Qt 129 - Introduction to QMediaPlayer
//   https://www.youtube.com/watch?v=PutunNtVpto
#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    connect(player, &QMediaPlayer::positionChanged, this, &MyWidget::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MyWidget::on_durationChannged);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MyWidget::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MyWidget::on_buttonStart_clicked()
{
    //Load the file
    player->setMedia(QUrl::fromLocalFile("/Users/dchou/Qt5.9.8/5.9.8/Src/qtwebengine/src/3rdparty/chromium/third_party/webrtc/examples/objc/AppRTCMobile/ios/resources/mozart.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void MyWidget::on_buttonStop_clicked()
{
    player->stop();
}

void MyWidget::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);

}

void MyWidget::on_durationChannged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);

}
