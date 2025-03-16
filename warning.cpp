#include "warning.h"
#include "ui_warning.h"
#include "start.h"
#include <QTimer>
Warning::Warning(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Warning)
{
    ui->setupUi(this);
    QString text ="<p>From time to time you will be asked to make a choice. Your choice may lead to success or disaster!</p>"
                   "<p>The adventures you take are a result of your choice. You are responsible because you choose!</p>"
                   "<p>Remember you cannot go back! Think carefully before you make a move! One mistake can be your last . . . or it may lead you to fame and fortune ! ! !</p>";
    ui->textEdit->setHtml(text);

}

Warning::~Warning()
{
    delete ui;
}

void Warning::on_p_next_clicked()
{
    start *st = new start();
    st->setAttribute(Qt::WA_DeleteOnClose);
    st->showFullScreen();
    QTimer::singleShot(1000, this, [this]() {
        this->close();
    });
}

