/********************************************************************************
** Form generated from reading UI file 'page4.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE4_H
#define UI_PAGE4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page4
{
public:
    QLabel *label;
    QTextEdit *story;
    QPushButton *p_next;
    QTextEdit *story_2;
    QTextEdit *story_3;
    QTextEdit *story_4;
    QTextEdit *story_5;
    QLabel *blur;
    QTextEdit *story_0;

    void setupUi(QWidget *Page4)
    {
        if (Page4->objectName().isEmpty())
            Page4->setObjectName("Page4");
        Page4->resize(1920, 1080);
        Page4->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label = new QLabel(Page4);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/h.png")));
        label->setScaledContents(true);
        story = new QTextEdit(Page4);
        story->setObjectName("story");
        story->setEnabled(false);
        story->setGeometry(QRect(300, 660, 1321, 221));
        story->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story->setReadOnly(true);
        p_next = new QPushButton(Page4);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 980, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_2 = new QTextEdit(Page4);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);
        story_3 = new QTextEdit(Page4);
        story_3->setObjectName("story_3");
        story_3->setEnabled(false);
        story_3->setGeometry(QRect(300, 660, 1321, 221));
        story_3->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_3->setReadOnly(true);
        story_4 = new QTextEdit(Page4);
        story_4->setObjectName("story_4");
        story_4->setEnabled(false);
        story_4->setGeometry(QRect(300, 660, 1321, 221));
        story_4->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_4->setReadOnly(true);
        story_5 = new QTextEdit(Page4);
        story_5->setObjectName("story_5");
        story_5->setEnabled(false);
        story_5->setGeometry(QRect(300, 660, 1321, 221));
        story_5->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_5->setReadOnly(true);
        blur = new QLabel(Page4);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        story_0 = new QTextEdit(Page4);
        story_0->setObjectName("story_0");
        story_0->setEnabled(false);
        story_0->setGeometry(QRect(300, 660, 1321, 221));
        story_0->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_0->setReadOnly(true);
        label->raise();
        blur->raise();
        p_next->raise();
        story->raise();
        story_2->raise();
        story_3->raise();
        story_4->raise();
        story_5->raise();
        story_0->raise();

        retranslateUi(Page4);

        QMetaObject::connectSlotsByName(Page4);
    } // setupUi

    void retranslateUi(QWidget *Page4)
    {
        Page4->setWindowTitle(QCoreApplication::translate("Page4", "Form", nullptr));
        label->setText(QString());
        p_next->setText(QCoreApplication::translate("Page4", "Continue", nullptr));
        blur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Page4: public Ui_Page4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE4_H
