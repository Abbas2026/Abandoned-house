#ifndef PAGE45_H
#define PAGE45_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page45;
}

class Page45 : public QWidget
{
    Q_OBJECT

public:
    explicit Page45(QWidget *parent = nullptr);
    ~Page45();

private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::Page45 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);
};

#endif // PAGE45_H
