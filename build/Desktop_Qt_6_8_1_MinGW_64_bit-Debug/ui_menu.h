/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *l_name_game;
    QGraphicsView *graphicsView;
    QPushButton *p_start;
    QPushButton *p_load;
    QPushButton *p_about;
    QPushButton *p_exit;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        Menu->setMinimumSize(QSize(1920, 1080));
        Menu->setMaximumSize(QSize(16777215, 1080));
        Menu->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(0, 1080));
        centralwidget->setMaximumSize(QSize(16777215, 0));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, -1, 1922, 1080));
        widget->setMinimumSize(QSize(1922, 1080));
        widget->setMaximumSize(QSize(1922, 1080));
        widget->setStyleSheet(QString::fromUtf8(""));
        l_name_game = new QLabel(widget);
        l_name_game->setObjectName("l_name_game");
        l_name_game->setGeometry(QRect(60, 80, 671, 71));
        l_name_game->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"color: #660000;\n"
"font: 40pt \"Nosifer\";\n"
"letter-spacing: -4px;\n"
"word-spacing: 9px;"));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, -50, 1922, 1180));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 25, 25);"));
        p_start = new QPushButton(widget);
        p_start->setObjectName("p_start");
        p_start->setGeometry(QRect(120, 210, 551, 101));
        p_start->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_start->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"color: rgb(0, 0, 0);\n"
"letter-spacing: -1px;\n"
"word-spacing: 2px;\n"
"font: 60pt \"Zombie Holocaust\";\n"
"border:none;\n"
"\n"
""));
        p_load = new QPushButton(widget);
        p_load->setObjectName("p_load");
        p_load->setGeometry(QRect(240, 340, 321, 101));
        p_load->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_load->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"color: rgb(0, 0, 0);\n"
"letter-spacing: -1px;\n"
"word-spacing: 2px;\n"
"font: 60pt \"Zombie Holocaust\";\n"
"border:none;\n"
"\n"
""));
        p_about = new QPushButton(widget);
        p_about->setObjectName("p_about");
        p_about->setGeometry(QRect(210, 490, 371, 91));
        p_about->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_about->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"color: rgb(0, 0, 0);\n"
"letter-spacing: -1px;\n"
"word-spacing: 2px;\n"
"font: 60pt \"Zombie Holocaust\";\n"
"border:none;\n"
"\n"
""));
        p_exit = new QPushButton(widget);
        p_exit->setObjectName("p_exit");
        p_exit->setGeometry(QRect(290, 610, 211, 151));
        p_exit->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"color: rgb(0, 0, 0);\n"
"letter-spacing: -1px;\n"
"word-spacing: 2px;\n"
"font: 60pt \"Zombie Holocaust\";\n"
"border:none;\n"
"\n"
""));
        graphicsView->raise();
        l_name_game->raise();
        p_start->raise();
        p_load->raise();
        p_about->raise();
        p_exit->raise();
        Menu->setCentralWidget(centralwidget);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        l_name_game->setText(QCoreApplication::translate("Menu", "Abandoned house", nullptr));
        p_start->setText(QCoreApplication::translate("Menu", "START A NEW GAME", nullptr));
        p_load->setText(QCoreApplication::translate("Menu", "LOAD GAME", nullptr));
        p_about->setText(QCoreApplication::translate("Menu", "About game", nullptr));
        p_exit->setText(QCoreApplication::translate("Menu", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
