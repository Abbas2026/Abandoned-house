#ifndef PAGE5_H
#define PAGE5_H

#include <QWidget>
#include <QTextEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QStackedWidget>
namespace Ui {
class Page5;
}

class Page5 : public QWidget
{
    Q_OBJECT

public:
    explicit Page5(QWidget *parent = nullptr);
    ~Page5();
private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::Page5 *ui;
    QStackedWidget *stackedWidget;
    int currentIndex;
    int next;
    void typewriterEffect(QTextEdit *textEdit, const QString &fullHtml);
    Qt::Alignment getTextAlignment(const QString &html);
    QString extractPlainTextFromHtml(const QString &html);

};

#endif // PAGE5_H
