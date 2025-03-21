#include "page8.h"
#include "ui_page8.h"
#include "styles.h"
#include "page14.h"
#include "edithtml.h"
Page8::Page8(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page8)
  , currentIndex(0), next(0)
{
    ui->setupUi(this);
    ui->right_btn->hide();
    ui->left_btn->hide();
    ui->p_next->setEnabled(false);
    ui->right_btn->setEnabled(false);
    ui->left_btn->setEnabled(false);

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
    QString text1 = "<p>You start up the stairs, trying to make as little noise as possible. The railing is falling off, and the dust and cobwebs get thicker each step of the way until you reach the landing, which is dimly lit by a pale yellow light coming through a circular stained glass window. Steps continue up in two directions from the landing, but on the same level is a hall leading to a door that is slightly ajar. You walk up to it and gently push it open</p>";
    QString text2 = "<p>Before you is a dingy room filled with furniture and trunks, an old-fashioned radio, a grandfather clock, a rocking horse, some coils of rope, piles of books and, on the dusty floor, a dead mouse. In the back of the room is a large closet</p>";

    ui->story_0->setHtml(text0);
    ui->story_1->setHtml(text1);
    ui->story_2->setHtml(text2);

    connect(ui->p_next, &QPushButton::clicked, this, &Page8::fadeText);

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

Page8::~Page8()
{
    delete ui;
}


void Page8::fadeText()
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

    if (currentIndex == stackedWidget->count() - 2) {
        ui->right_btn->show();
        ui->left_btn->show();
        ui->p_next->hide();
    }
}

void Page8::on_p_next_clicked()
{
    if (next) {
        this->close();
    }
}

void Page8::on_right_btn_clicked()
{
    Page14 *page14 = new Page14();
    page14->setAttribute(Qt::WA_DeleteOnClose);
    page14->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->close();
    });
}

void Page8::on_left_btn_clicked()
{
    this->close();

}


void Page8::typewriterEffect(QTextEdit *textEdit, const QString &fullHtml)
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
            ui->right_btn->setEnabled(true);
            ui->left_btn->setEnabled(true);
        }
    });

    timer->start(50);
}

