#include "menu.h"
#include "start.h"
#include <QApplication>
#include "warning.h"
#include "page4.h"
Menu *globalMenu = nullptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    globalMenu = new Menu();
    globalMenu->showFullScreen();
    return a.exec();
}
