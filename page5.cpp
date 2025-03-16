#include "page5.h"
#include "ui_page5.h"
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>
#include "styles.h"
#include "page5.h"
Page5::Page5(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page5)
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
    QString text1 = "<p>There are rows of sinks and counters and a huge black oven. The floor is laid with dark red tiles, many of them chipped or loose. The windows are covered with cloth shades, and you raise one of them to let in more light</p>";
    QString text2 = "<p>On your right is a flight of steps leading from the kitchen upstairs; to the left is a swinging door, which you imagine leads to the dining room</p>";

    ui->story_0->setHtml(text0);
    ui->story_1->setHtml(text1);
    ui->story_2->setHtml(text2);

    connect(ui->p_next, &QPushButton::clicked, this, &Page5::fadeText);

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

Page5::~Page5()
{
    delete ui;
}



void Page5::fadeText()
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

void Page5::on_p_next_clicked()
{
    if (next) {
        this->close();
    }
}

void Page5::on_right_btn_clicked()
{
    // Page5 *page5 = new Page5();
    // page5->setAttribute(Qt::WA_DeleteOnClose);
    // page5->showFullScreen();
    // QTimer::singleShot(1000, this, [this]() {
    //     this->hide();
    // });
}

void Page5::on_left_btn_clicked()
{
    this->hide();

}


void Page5::typewriterEffect(QTextEdit *textEdit, const QString &fullHtml)
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
Qt::Alignment Page5::getTextAlignment(const QString &html)
{
    if (html.contains("text-align: center") || html.contains("align=\"center\"")) {
        return Qt::AlignCenter;
    }
    if (html.contains("text-align: right") || html.contains("align=\"right\"")) {
        return Qt::AlignRight;
    }
    return Qt::AlignLeft; // پیش‌فرض چپ‌چین
}
QString Page5::extractPlainTextFromHtml(const QString &html) {
    QTextDocument doc;
    doc.setHtml(html);
    return doc.toPlainText();  // فقط متن خام را برمی‌گرداند
}
