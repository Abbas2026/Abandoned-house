#include "page45.h"
#include "ui_page45.h"
#include "edithtml.h"
#include "styles.h"
#include "page84.h"
Page45::Page45(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page45)
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
        ui->story_3,
        ui->story_4,

    };
    for (QTextEdit *textEdit : textEdits) {
        textEdit->setProperty("readOnly", true);
        textEdit->setProperty("horizontalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setProperty("verticalScrollBarPolicy", Qt::ScrollBarAlwaysOff);
        textEdit->setStyleSheet(texteditstyle);
    }
    QString text0 = "";
    QString text1 = "<p>You follow the tunnel for about a hundred feet before it opens up into a wide space filled with casks and racks of bottles. This must be a special cave where Mr. Bigley kept his wines</p>";
    QString text2 = "<p>At the far end of the cave is a chest with three drawers. The top one is locked. You try another one of your keys. It works! You pull open the drawer and take out some yellowed, crumbling papers you find there. Among them is a letter, written in a shaky hand, which reads :</p>";
    QString text3 = "<p>[To Whom It May Concern]   I, Horace A.Bigley, am a prisoner in my own house, held by the ghost of my wife, Melissa Bigley, who died one month ago today, and now has the power to transform people into . . .</p>";
    QString text4 = "<p>Before you can finish reading the note, you feel a presence. You whirl your flashlight around but it flickers in and out. In the final, flickering light, you see a figure and, even now in the dark, you can feel its eyes fixed upon you. You reach for the rack of wine bottles and pull one out. It may be of no use against a ghost, but it is your only weapon</p>";

    ui->story_0->setHtml(text0);
    ui->story_1->setHtml(text1);
    ui->story_2->setHtml(text2);
    ui->story_3->setHtml(text3);
    ui->story_4->setHtml(text4);



    connect(ui->p_next, &QPushButton::clicked, this, &Page45::fadeText);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->story_0);
    stackedWidget->addWidget(ui->story_1);
    stackedWidget->addWidget(ui->story_2);
    stackedWidget->addWidget(ui->story_3);
    stackedWidget->addWidget(ui->story_4);
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

Page45::~Page45()
{
    delete ui;
}


void Page45::fadeText()
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

void Page45::typewriterEffect(QTextEdit *textEdit, const QString &fullHtml)
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
void Page45::on_p_next_clicked()
{
    if (next) {
        this->close();
    }
}

void Page45::on_right_btn_clicked()
{
    Page84 *page84 = new Page84();
    page84->setAttribute(Qt::WA_DeleteOnClose);
    page84->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->close();
    });
}

void Page45::on_left_btn_clicked()
{
    this->close();

}




