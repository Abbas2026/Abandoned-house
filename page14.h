#ifndef PAGE14_H
#define PAGE14_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page14;
}

class Page14 : public QWidget
{
    Q_OBJECT

public:
    explicit Page14(QWidget *parent = nullptr);
    ~Page14();

private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::Page14 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);
};

#endif // PAGE14_H
