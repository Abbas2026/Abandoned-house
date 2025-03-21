#include "page84.h"
#include "ui_page84.h"
#include "styles.h"
#include "menu.h"
#include "SignalManager.h"
Page84::Page84(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page84)
    , currentIndex(0), next(0)

{
    ui->setupUi(this);
    ui->p_next->setEnabled(false);
    ui->p_end->hide();

    QList<QTextEdit*> textEdits = {
        ui->story_0,
        ui->story_1,
        ui->story_2,
        ui->story_3,
        ui->story_4,
        ui->story_5,
        ui->story_6,
        ui->story_7,
        ui->story_8,

    };
    for (QTextEdit *textEdit : textEdits) {
        textEdit->setProperty("readOnly", true);
        textEdit->setProperty("horizontalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setProperty("verticalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setStyleSheet(texteditstyle);
    }
    QString text0 = "";
    QString text1 = "<p style='text-align: center;'>You lunge forward and swing the wine bottle, striking something. The bottle breaks, and wine splatters all over you. A voice cries out—it's Michael. He screams</p>";
    QString text2 = "<p style='text-align: right;'><h3>MICHAEL</h3>It's me!</p>";
    QString text3 = "<p><h3>YOU</h3>I'm sorry. I thought you were going to get me</p>";
    QString text4 = "<p style='text-align: center;'>You shine your light on Michael's head. Fortunately, he seems not to be injured</p>";
    QString text5 = "<p><h3>YOU</h3>Follow me closely,We'll get out of here</p>";
    QString text6 = "<p style='text-align: center;'>Suddenly, you hear a roaring sound. Clouds of dust rise around you. Loose dirt scatters down around you. You shine your light toward the tunnel; it is blocked off, but there is light coming through from above. Suddenly, the roof of the tunnel is caving in. You are being buried alive! a voice calls down:</p>";
    QString text7 = "<p style='text-align: right;'><h3>?</h3>Don't worry,I'm a policeman! I've radioed for help. We'll have you out of there soon</p>";
    QString text8 = "<p style='text-align: center;'>But even as you hear his words, you are gasping your last breath, another victim of the curse of Abandoned house</p>";





    ui->story_0->setHtml(text0);
    ui->story_1->setHtml(text1);
    ui->story_2->setHtml(text2);
    ui->story_3->setHtml(text3);
    ui->story_4->setHtml(text4);
    ui->story_5->setHtml(text5);
    ui->story_6->setHtml(text6);
    ui->story_7->setHtml(text7);
    ui->story_8->setHtml(text8);



    connect(ui->p_next, &QPushButton::clicked, this, &Page84::fadeText);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->story_0);
    stackedWidget->addWidget(ui->story_1);
    stackedWidget->addWidget(ui->story_2);
    stackedWidget->addWidget(ui->story_3);
    stackedWidget->addWidget(ui->story_4);
    stackedWidget->addWidget(ui->story_5);
    stackedWidget->addWidget(ui->story_6);
    stackedWidget->addWidget(ui->story_7);
    stackedWidget->addWidget(ui->story_8);

    stackedWidget->setCurrentIndex(0);
    stackedWidget->setGeometry(300, 660, 1321, 211);

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(10);
    ui->blur->setGraphicsEffect(blurEffect);

    ui->blur->setStyleSheet(
        "background-color: rgba(0, 0, 0, 100);"
        );
    fadeText();
}

Page84::~Page84()
{
    delete ui;
}


void Page84::fadeText()
{
    ui->p_next->setEnabled(false);

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

    });

    fadeOut->start();
    if (currentIndex == stackedWidget->count() - 2) {
        ui->p_next->hide();
        ui->p_end->show();

    }
}

void Page84::on_p_next_clicked()
{
}




void Page84::on_p_end_clicked()
{
emit SignalManager::instance()->stopmusic();
    Menu *menu = new Menu();
    menu->setAttribute(Qt::WA_DeleteOnClose);
    menu->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->close();
    });
}

