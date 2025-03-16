/********************************************************************************
** Form generated from reading UI file 'page5.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE5_H
#define UI_PAGE5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page5
{
public:
    QLabel *label;
    QPushButton *right_btn;
    QPushButton *left_btn;
    QPushButton *p_next;
    QTextEdit *story_1;
    QTextEdit *story_2;
    QLabel *blur;
    QTextEdit *story_0;

    void setupUi(QWidget *Page5)
    {
        if (Page5->objectName().isEmpty())
            Page5->setObjectName("Page5");
        Page5->resize(1920, 1080);
        Page5->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label = new QLabel(Page5);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/a.jpg")));
        label->setScaledContents(true);
        right_btn = new QPushButton(Page5);
        right_btn->setObjectName("right_btn");
        right_btn->setGeometry(QRect(1270, 980, 521, 61));
        right_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        right_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        left_btn = new QPushButton(Page5);
        left_btn->setObjectName("left_btn");
        left_btn->setGeometry(QRect(150, 980, 521, 61));
        left_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        left_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        p_next = new QPushButton(Page5);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 980, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_1 = new QTextEdit(Page5);
        story_1->setObjectName("story_1");
        story_1->setEnabled(false);
        story_1->setGeometry(QRect(300, 660, 1321, 221));
        story_1->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_1->setReadOnly(true);
        story_2 = new QTextEdit(Page5);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);
        blur = new QLabel(Page5);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        story_0 = new QTextEdit(Page5);
        story_0->setObjectName("story_0");
        story_0->setEnabled(false);
        story_0->setGeometry(QRect(300, 660, 1321, 221));
        story_0->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_0->setReadOnly(true);
        label->raise();
        blur->raise();
        story_1->raise();
        story_2->raise();
        left_btn->raise();
        p_next->raise();
        right_btn->raise();
        story_0->raise();

        retranslateUi(Page5);

        QMetaObject::connectSlotsByName(Page5);
    } // setupUi

    void retranslateUi(QWidget *Page5)
    {
        Page5->setWindowTitle(QCoreApplication::translate("Page5", "Form", nullptr));
        label->setText(QString());
        right_btn->setText(QCoreApplication::translate("Page5", "You are climbing the stairs", nullptr));
        left_btn->setText(QCoreApplication::translate("Page5", "You go into the dining room", nullptr));
        p_next->setText(QCoreApplication::translate("Page5", "Continue", nullptr));
        blur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Page5: public Ui_Page5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE5_H
