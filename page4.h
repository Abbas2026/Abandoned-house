#ifndef PAGE4_H
#define PAGE4_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page4;
}

class Page4 : public QWidget
{
    Q_OBJECT

public:
    explicit Page4(QWidget *parent = nullptr);
    ~Page4();

private slots:
    void on_p_next_clicked();
    void fadeText();

private:
    Ui::Page4 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;

};

#endif // PAGE4_H
