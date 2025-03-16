#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    void setupVideoBackground();
    void setupBackgroundMusic();
    void applyStyles();
    void stopMusic();

private slots:
    void on_p_exit_clicked();
    void startAnimation();

    void on_p_start_clicked();

    void on_p_load_clicked();

    void on_p_about_clicked();

private:
    Ui::Menu *ui;
private:
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;

};
#endif // MENU_H
