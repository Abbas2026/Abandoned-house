#include "page4.h"
#include "ui_page4.h"
#include "styles.h"
#include "page5.h"
Page4::Page4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page4)
    , currentIndex(0), next(0)
{
    ui->setupUi(this);
    ui->p_next->setEnabled(false);

    QList<QTextEdit*> textEdits = {
        ui->story_0,
        ui->story,
        ui->story_2,
        ui->story_3,
        ui->story_4,
        ui->story_5,
    };
    for (QTextEdit *textEdit : textEdits) {
        textEdit->setProperty("readOnly", true);
        textEdit->setProperty("horizontalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setProperty("verticalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setStyleSheet(texteditstyle);
    }
    QString text0 = "";
    QString text1 = "<p><h3>YOU</h3>I’ll do it</p>";
    QString text2 = "<p style='text-align: right;'><h3>MICHAEL</h3>OK, When are you going? Jane and I will watch you</p>";
    QString text3 = "<p style='text-align: right;'><h3>JANE</h3>We’ll want to say good-bye to you</p>";
    QString text4 = "<p style='text-align: center;'>You take time to get a flashlight from the house, and then the three of you set off for Abandoned house. You feel a bit nervous, but it’s a beautiful day, and you keep telling yourself there is really nothing to worry about</p>";
    QString text5 = "<p style='text-align: center;'>As you approach it, the house looks bleak and forbidding, like some medieval fortress. A dark cloud passes in front of the sun. The windows look dull in your eyes. You wish you hadn’t agreed to go inside. But it’s too late to back out now, so, while Michael and Jane watch from a distance, you walk around the house and try all the doors.Every one of them is locked except for one in the back of the house. You wave to your cousins, open the door and walk into an entryway that leads to a large kitchen</p>";

    ui->story_0->setHtml(text0);
    ui->story->setHtml(text1);
    ui->story_2->setHtml(text2);
    ui->story_3->setHtml(text3);
    ui->story_4->setHtml(text4);
    ui->story_5->setHtml(text5);
    connect(ui->p_next, &QPushButton::clicked, this, &Page4::fadeText);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->story_0);
    stackedWidget->addWidget(ui->story);
    stackedWidget->addWidget(ui->story_2);
    stackedWidget->addWidget(ui->story_3);
    stackedWidget->addWidget(ui->story_4);
    stackedWidget->addWidget(ui->story_5);
    stackedWidget->setCurrentIndex(0);
    stackedWidget->setGeometry(300, 660, 1321, 211);

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(10);
    ui->blur->setGraphicsEffect(blurEffect);
    ui->blur->setStyleSheet(
        "background-color: rgba(0, 0, 0, 50);"
        );
        fadeText();
}

Page4::~Page4()
{
    delete ui;
}

void Page4::fadeText()
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
}

void Page4::on_p_next_clicked()
{
    if (next) {
        Page5 *page5 = new Page5();
        page5->setAttribute(Qt::WA_DeleteOnClose);
        page5->showFullScreen();
        QTimer::singleShot(1000, this, [this]() {
            this->hide();
        });
    }
}
