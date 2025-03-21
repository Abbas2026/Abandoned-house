#ifndef PAGE84_H
#define PAGE84_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page84;
}

class Page84 : public QWidget
{
    Q_OBJECT

public:
    explicit Page84(QWidget *parent = nullptr);
    ~Page84();
private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_p_end_clicked();

private:
    Ui::Page84 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;

};

#endif // PAGE84_H
