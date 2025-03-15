#include "loading.h"
#include "ui_loading.h"
#include <QProgressBar>
#include <QTimer>
#include "start.h"
Loading::Loading(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Loading)
{
    startcreated=false;
    ui->setupUi(this);
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->progressBar->setTextVisible(false);
    ui->progressBar->setStyleSheet(
        "QProgressBar {"
        "   border: none;"
        "   border-radius: 5px;"
        "   background-color: rgba(72, 74, 89, 0);"
        "   text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "   background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop:0 #a6c3c7, stop:1 #f0e68c);"
        "   border-radius: 5px;"
        "}"
        );
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Loading::updateProgress);
    timer->start(200);
}

Loading::~Loading()
{
    delete ui;
}

void Loading::updateProgress() {
    int value = ui->progressBar->value();
    if (value < 100) {
        ui->progressBar->setValue(value + 5);
    } else {
        QTimer::singleShot(0, this, &Loading::goToNextPage);
    }
}

void Loading::goToNextPage() {
     if (!startcreated) {
        startcreated=true;
    start *st = new start();
    st->setAttribute(Qt::WA_DeleteOnClose);
    st->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->close();
    });
     }
}
