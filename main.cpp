#include "menu.h"
#include "start.h"
#include <QApplication>

Menu *globalMenu = nullptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    globalMenu = new Menu();
    globalMenu->showFullScreen();
    return a.exec();
}
