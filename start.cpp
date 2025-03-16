#include "start.h"
#include "ui_start.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include "styles.h"
#include "menu.h"
#include "warning.h"
#include "page4.h"
extern Menu *globalMenu;
start::start(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::start)
    , currentIndex(0), next(0)
{
    ui->setupUi(this);
    if (globalMenu) {
        globalMenu->close();
        globalMenu->stopMusic();
    }
    ui->right_btn->hide();
    ui->left_btn->hide();
    ui->right_btn->setEnabled(false);
    ui->left_btn->setEnabled(false);
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl::fromLocalFile("E:/Abandoned-house/music/main.mp3"));
    audioOutput->setVolume(20);
    musicPlayer->setLoops(QMediaPlayer::Infinite);
    musicPlayer->play();
    QList<QTextEdit*> textEdits = {
        ui->story,
        ui->story_1,
        ui->story_2,
        ui->story_3,
        ui->story_4,
        ui->story_5,
        ui->story_6,
        ui->story_7,
        ui->story_8,
        ui->story_9,
        ui->story_10
    };

    for (QTextEdit *textEdit : textEdits) {
        textEdit->setProperty("readOnly", true);
        textEdit->setProperty("horizontalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setProperty("verticalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setStyleSheet(texteditstyle);
    }
    QString text1 = "<p style='text-align: center;'>Vacation is here and you’re visiting your cousins Michael and Jane for a few days at their new home in Connecticut. Soon after you arrive, they take you on a tour of their neighborhood, along shady streets lined with cozy houses with neatly-trimmed lawns. At the top of a hill you notice a huge stone house unlike any you have ever seen. It has turrets, walled terraces and a square tower that looks like a giant chimney. Some of the windows are boarded up and others are hidden by vines and bushes. There is a big dog chained in front of the little cottage nearby.</p>";
    QString text1_1="<p><h3>YOU</h3>Whether someone lives in the house?</p>";
    QString text2 = "<p style='text-align: right;'><h3>MICHAEL</h3>Abandoned house? Most people around here wouldn’t live there for a million dollars</p>";
    QString text3 = "<p style='text-align: right;'><h3>MICHAEL</h3>They say it is cursed and some people who have gone inside have never been seen again. What happened to them is still a mystery.</p>";
    QString text4 = "<p style='text-align: right;'><h3>MICHAEL</h3>Mrs.Bigley lived in Abandoned house alone with her cat for many years. When she died, she left instructions in her will that the cat could live there for the rest of its life. People say that she put a curse on the house so that no one would bother the cat.</p>";
    QString text5 = "<p><h3>YOU</h3>Haven’t the police investigated?</p>";
    QString text6 = "<p style='text-align: right;'><h3>MICHAEL</h3>The police never found anyone—only the cat, but some people say Mrs. Bigley never died at all and that she’s still living there herself!</p>";
    QString text7 = "<p><h3>YOU</h3>What does the caretaker say?</p>";
    QString text8 = "<p style='text-align: right;'><h3>MICHAEL</h3>He doesn’t say anything, Some say he’s crazy, and some say he’s just mean, but I guess he’s afraid of the curse too, because I hear he won’t set foot inside Abandoned house.</p>";
    QString text9 = "<p><h3>YOU</h3>You’re not kidding?</p>";
    QString text10= "<p style='text-align: right;'><h3>MICHAEL</h3>If you think we’re kidding, why don’t you go inside?</p>";

    ui->story->setHtml(text1);
    ui->story_1->setHtml(text1_1);
    ui->story_2->setHtml(text2);
    ui->story_3->setHtml(text3);
    ui->story_4->setHtml(text4);
    ui->story_5->setHtml(text5);
    ui->story_6->setHtml(text6);
    ui->story_7->setHtml(text7);
    ui->story_8->setHtml(text8);
    ui->story_9->setHtml(text9);
    ui->story_10->setHtml(text10);

    connect(ui->p_next, &QPushButton::clicked, this, &start::fadeText);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->story);
    stackedWidget->addWidget(ui->story_1);
    stackedWidget->addWidget(ui->story_2);
    stackedWidget->addWidget(ui->story_3);
    stackedWidget->addWidget(ui->story_4);
    stackedWidget->addWidget(ui->story_5);
    stackedWidget->addWidget(ui->story_6);
    stackedWidget->addWidget(ui->story_7);
    stackedWidget->addWidget(ui->story_8);
    stackedWidget->addWidget(ui->story_9);
    stackedWidget->addWidget(ui->story_10);
    stackedWidget->setCurrentIndex(0);
    stackedWidget->setGeometry(300, 660, 1321, 211);

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(10);
    ui->blur->setGraphicsEffect(blurEffect);
    ui->blur->setStyleSheet(
        "background-color: rgba(0, 0, 0, 100);"
        );
}

start::~start()
{
    delete ui;
}

void start::fadeText()
{
    ui->p_next->setEnabled(false);
    ui->right_btn->setEnabled(false);
    ui->left_btn->setEnabled(false);
    QTextEdit *currentTextEdit = qobject_cast<QTextEdit*>(stackedWidget->widget(currentIndex));
    QTextEdit *nextTextEdit = nullptr;

    if (currentIndex == stackedWidget->count() - 1) {
        ui->p_next->setEnabled(true);
        next = 1;
        on_p_next_clicked();
        return;
    }

    else {
        nextTextEdit = qobject_cast<QTextEdit*>(stackedWidget->widget(currentIndex + 1));
    }

    if (!currentTextEdit || !nextTextEdit) {
        ui->p_next->setEnabled(true);
        return;
    }

    QGraphicsOpacityEffect *fadeOutEffect = new QGraphicsOpacityEffect(currentTextEdit);
    currentTextEdit->setGraphicsEffect(fadeOutEffect);

    QPropertyAnimation *fadeOut = new QPropertyAnimation(fadeOutEffect, "opacity");
    fadeOut->setDuration(1000);
    fadeOut->setStartValue(1.0);
    fadeOut->setEndValue(0.0);

    QGraphicsOpacityEffect *fadeInEffect = new QGraphicsOpacityEffect(nextTextEdit);
    nextTextEdit->setGraphicsEffect(fadeInEffect);
    fadeInEffect->setOpacity(0.0);

    QPropertyAnimation *fadeIn = new QPropertyAnimation(fadeInEffect, "opacity");
    fadeIn->setDuration(1000);
    fadeIn->setStartValue(0.0);
    fadeIn->setEndValue(1.0);

    connect(fadeOut, &QPropertyAnimation::finished, this, [this, nextTextEdit, fadeIn]() {
        stackedWidget->setCurrentWidget(nextTextEdit);
        currentIndex = currentIndex + 1;
        fadeIn->start();
    });

    connect(fadeIn, &QPropertyAnimation::finished, this, [this]() {
        ui->p_next->setEnabled(true);
        ui->right_btn->setEnabled(true);
        ui->left_btn->setEnabled(true);
    });

    fadeOut->start();
    if(currentIndex == stackedWidget->count() - 2){
        ui->right_btn->show();
        ui->left_btn->show();
        ui->p_next->hide();
    }
}

void start::on_p_next_clicked()
{
    if (next) {
        this->close();
    }
}

void start::on_right_btn_clicked()
{
    Page4 *page4 = new Page4();
    page4->setAttribute(Qt::WA_DeleteOnClose);
    page4->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->hide();
    });
}

void start::on_left_btn_clicked()
{
    this->hide();

}
