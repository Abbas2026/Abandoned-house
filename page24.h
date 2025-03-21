#ifndef PAGE24_H
#define PAGE24_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page24;
}

class Page24 : public QWidget
{
    Q_OBJECT

public:
    explicit Page24(QWidget *parent = nullptr);
    ~Page24();

private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::Page24 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);
};

#endif // PAGE24_H
