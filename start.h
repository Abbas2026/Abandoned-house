#ifndef START_H
#define START_H

#include <QWidget>
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

private slots:
    void on_p_next_clicked();
    void fadeText();
    void on_right_btn_clicked();
    void on_left_btn_clicked();

private:
    Ui::start *ui;
    int currentIndex;
    int next;
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;
    QStackedWidget *stackedWidget;

};

#endif // START_H
