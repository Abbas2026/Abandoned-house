#include "menu.h"
#include "ui_menu.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <styles.h>
#include <loading.h>
Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    setupVideoBackground();
    setupBackgroundMusic();
    applyStyles();
    connect(ui->p_start, &QPushButton::clicked, this, &Menu::startAnimation);
    connect(ui->p_load, &QPushButton::clicked, this, &Menu::startAnimation);
    connect(ui->p_about, &QPushButton::clicked, this, &Menu::startAnimation);
    connect(ui->p_exit, &QPushButton::clicked, this, &Menu::startAnimation);
}

Menu::~Menu()
{
    delete ui;
}
void Menu::applyStyles(){
    ui->p_start->setStyleSheet(baseStyle);
    ui->p_load->setStyleSheet(baseStyle);
    ui->p_about->setStyleSheet(baseStyle);
    ui->p_exit->setStyleSheet(baseStyle);


}
void Menu::setupVideoBackground() {

    QMediaPlayer *player = new QMediaPlayer(this);
    QGraphicsVideoItem *videoItem = new QGraphicsVideoItem();
    player->setVideoOutput(videoItem);
    player->setSource(QUrl::fromLocalFile("E:/game/Abandoned_house/d.mp4"));
    player->setLoops(QMediaPlayer::Infinite);
    player->play();
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(videoItem);
    QGraphicsView *graphicsView = findChild<QGraphicsView *>("graphicsView");
    if (graphicsView) {
        graphicsView->setScene(scene);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        videoItem->setSize(graphicsView->size());

    }
}

void Menu::setupBackgroundMusic() {
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    musicPlayer->setAudioOutput(audioOutput);

    musicPlayer->setSource(QUrl::fromLocalFile("E:/game/Abandoned_house/main.mp3"));

    audioOutput->setVolume(50);

    musicPlayer->setLoops(QMediaPlayer::Infinite);

    musicPlayer->play();
}

void Menu::on_p_exit_clicked()
{
    this->close();
}

void Menu::startAnimation() {

    QList<QPushButton*> buttons = {ui->p_start, ui->p_load, ui->p_about, ui->p_exit};

    int delay = 0;
    for (QPushButton *button : buttons) {
        QTimer::singleShot(delay, this, [this, button]() {
            QPropertyAnimation *animation = new QPropertyAnimation(button, "pos", this);
            animation->setDuration(1000);
            animation->setStartValue(button->pos());
            animation->setEndValue(QPoint(-button->width(), button->y()));
            animation->setEasingCurve(QEasingCurve::InOutQuad);
            animation->start();
        });
        delay += 200;
    }
}

void Menu::on_p_start_clicked()
{
    QTimer::singleShot(1200, this, [this]() {
        Loading *loading = new Loading();
        loading->setAttribute(Qt::WA_DeleteOnClose);
        loading->showFullScreen();
        QTimer::singleShot(1000, this, [this]() {
 this->close();
  });
    });
}

