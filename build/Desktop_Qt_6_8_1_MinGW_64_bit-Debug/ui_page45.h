/********************************************************************************
** Form generated from reading UI file 'page45.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE45_H
#define UI_PAGE45_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page45
{
public:
    QLabel *label;
    QLabel *blur;
    QPushButton *left_btn;
    QPushButton *right_btn;
    QPushButton *p_next;
    QTextEdit *story_0;
    QTextEdit *story_1;
    QTextEdit *story_2;
    QTextEdit *story_3;
    QTextEdit *story_4;

    void setupUi(QWidget *Page45)
    {
        if (Page45->objectName().isEmpty())
            Page45->setObjectName("Page45");
        Page45->resize(1920, 1080);
        Page45->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"\n"
""));
        label = new QLabel(Page45);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/45.jpg")));
        label->setScaledContents(true);
        blur = new QLabel(Page45);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        left_btn = new QPushButton(Page45);
        left_btn->setObjectName("left_btn");
        left_btn->setGeometry(QRect(150, 980, 521, 61));
        left_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        left_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        right_btn = new QPushButton(Page45);
        right_btn->setObjectName("right_btn");
        right_btn->setGeometry(QRect(1270, 980, 521, 61));
        right_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        right_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        p_next = new QPushButton(Page45);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 980, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_0 = new QTextEdit(Page45);
        story_0->setObjectName("story_0");
        story_0->setEnabled(false);
        story_0->setGeometry(QRect(300, 660, 1321, 221));
        story_0->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_0->setReadOnly(true);
        story_1 = new QTextEdit(Page45);
        story_1->setObjectName("story_1");
        story_1->setEnabled(false);
        story_1->setGeometry(QRect(300, 660, 1321, 221));
        story_1->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_1->setReadOnly(true);
        story_2 = new QTextEdit(Page45);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);
        story_3 = new QTextEdit(Page45);
        story_3->setObjectName("story_3");
        story_3->setEnabled(false);
        story_3->setGeometry(QRect(300, 660, 1321, 221));
        story_3->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_3->setReadOnly(true);
        story_4 = new QTextEdit(Page45);
        story_4->setObjectName("story_4");
        story_4->setEnabled(false);
        story_4->setGeometry(QRect(300, 660, 1321, 221));
        story_4->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_4->setReadOnly(true);
        label->raise();
        blur->raise();
        left_btn->raise();
        p_next->raise();
        right_btn->raise();
        story_0->raise();
        story_1->raise();
        story_2->raise();
        story_3->raise();
        story_4->raise();

        retranslateUi(Page45);

        QMetaObject::connectSlotsByName(Page45);
    } // setupUi

    void retranslateUi(QWidget *Page45)
    {
        Page45->setWindowTitle(QCoreApplication::translate("Page45", "Form", nullptr));
        label->setText(QString());
        blur->setText(QString());
        left_btn->setText(QCoreApplication::translate("Page45", "Ask, Who is this?", nullptr));
        right_btn->setText(QCoreApplication::translate("Page45", "Throw the bottle at it", nullptr));
        p_next->setText(QCoreApplication::translate("Page45", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page45: public Ui_Page45 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE45_H
