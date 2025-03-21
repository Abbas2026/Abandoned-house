#include "page44.h"
#include "ui_page44.h"
#include "edithtml.h"
#include "styles.h"
#include "page45.h"
Page44::Page44(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page44)
    , currentIndex(0), next(0)

{
    ui->setupUi(this);
    ui->p_next->setEnabled(false);

    QList<QTextEdit*> textEdits = {
        ui->story_0,
        ui->story_1,
        ui->story_2,

    };
    for (QTextEdit *textEdit : textEdits) {
        textEdit->setProperty("readOnly", true);
        textEdit->setProperty("horizontalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setProperty("verticalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setStyleSheet(texteditstyle);
    }
    QString text0 = "";
    QString text1 = "<p>You call up to the cat, but it remains immobile, its eyes fixed upon you. You stare back. It returns your gaze without blinking, then arches its back, hisses, and runs off.You follow it down a narrow corridor, but lose sight of it as it darts around a corner. Soon you come to a massive oak door. It is locked</p>";
    QString text2 = "<p>You try the keys on your key ring. One of them works! You pull open the door and shine your flashlight inside. There are steps leading down. Drawn by curiosity, you cautiously descend the stairs.When you reach the bottom, you find yourself in an underground tunnel. Its floor is paved with cobblestones; the walls and ceiling are supported by wooden beams. The air is damp and cold</p>";

    ui->story_0->setHtml(text0);
    ui->story_1->setHtml(text1);
    ui->story_2->setHtml(text2);

    connect(ui->p_next, &QPushButton::clicked, this, &Page44::fadeText);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->story_0);
    stackedWidget->addWidget(ui->story_1);
    stackedWidget->addWidget(ui->story_2);
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

Page44::~Page44()
{
    delete ui;
}


void Page44::fadeText()
{
    ui->p_next->setEnabled(false);

    QTextEdit *currentTextEdit = qobject_cast<QTextEdit*>(stackedWidget->widget(currentIndex));
    QTextEdit *nextTextEdit = nullptr;

    if (currentIndex == stackedWidget->count() - 1) {
        ui->p_next->setEnabled(true);
        next = 1;
        on_p_next_clicked();
        return;
    } else {
        nextTextEdit = qobject_cast<QTextEdit*>(stackedWidget->widget(currentIndex + 1));
    }

    if (!currentTextEdit || !nextTextEdit) {
        ui->p_next->setEnabled(true);
        return;
    }

    QString fullHtml = nextTextEdit->toHtml();
    nextTextEdit->clear();
    typewriterEffect(nextTextEdit, fullHtml);

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

    });

    fadeOut->start();
    fadeIn->start();

}

void Page44::typewriterEffect(QTextEdit *textEdit, const QString &fullHtml)
{
    QTimer *timer = new QTimer(this);
    int *currentLength = new int(0);

    QString plainText = extractPlainTextFromHtml(fullHtml);

    Qt::Alignment alignment = getTextAlignment(fullHtml);
    textEdit->clear();

    connect(timer, &QTimer::timeout, this, [=]() mutable {
        if (*currentLength < plainText.length()) {
            (*currentLength)++;
            textEdit->setPlainText(plainText.left(*currentLength));
            textEdit->setAlignment(alignment);
        } else {
            timer->stop();
            timer->deleteLater();
            delete currentLength;
            ui->p_next->setEnabled(true);

        }
    });

    timer->start(50);
}
void Page44::on_p_next_clicked()
{
    if (next) {
        Page45 *page45 = new Page45();
        page45->setAttribute(Qt::WA_DeleteOnClose);
        page45->showFullScreen();
        QTimer::singleShot(1000, this, [this]() {
            this->close();
        });
    }
}



