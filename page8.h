#ifndef PAGE8_H
#define PAGE8_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page8;
}

class Page8 : public QWidget
{
    Q_OBJECT

public:
    explicit Page8(QWidget *parent = nullptr);
    ~Page8();

private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::Page8 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);

};

#endif // PAGE8_H
