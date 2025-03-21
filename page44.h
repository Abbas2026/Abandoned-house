#ifndef PAGE44_H
#define PAGE44_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>

namespace Ui {
class Page44;
}

class Page44 : public QWidget
{
    Q_OBJECT

public:
    explicit Page44(QWidget *parent = nullptr);
    ~Page44();

private slots:
    void on_p_next_clicked();
    void fadeText();

private:
    Ui::Page44 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);
};

#endif // PAGE44_H
