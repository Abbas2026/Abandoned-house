/********************************************************************************
** Form generated from reading UI file 'page84.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE84_H
#define UI_PAGE84_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page84
{
public:
    QLabel *label;
    QLabel *blur;
    QTextEdit *story_0;
    QPushButton *p_next;
    QTextEdit *story_1;
    QTextEdit *story_2;
    QTextEdit *story_3;
    QTextEdit *story_4;
    QTextEdit *story_5;
    QTextEdit *story_6;
    QTextEdit *story_7;
    QTextEdit *story_8;
    QPushButton *p_end;

    void setupUi(QWidget *Page84)
    {
        if (Page84->objectName().isEmpty())
            Page84->setObjectName("Page84");
        Page84->resize(1920, 1080);
        Page84->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"\n"
""));
        label = new QLabel(Page84);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/84.jpg")));
        label->setScaledContents(true);
        blur = new QLabel(Page84);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        story_0 = new QTextEdit(Page84);
        story_0->setObjectName("story_0");
        story_0->setEnabled(false);
        story_0->setGeometry(QRect(300, 660, 1321, 221));
        story_0->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_0->setReadOnly(true);
        p_next = new QPushButton(Page84);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 960, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_1 = new QTextEdit(Page84);
        story_1->setObjectName("story_1");
        story_1->setEnabled(false);
        story_1->setGeometry(QRect(300, 660, 1321, 221));
        story_1->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_1->setReadOnly(true);
        story_2 = new QTextEdit(Page84);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);
        story_3 = new QTextEdit(Page84);
        story_3->setObjectName("story_3");
        story_3->setEnabled(false);
        story_3->setGeometry(QRect(300, 660, 1321, 221));
        story_3->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_3->setReadOnly(true);
        story_4 = new QTextEdit(Page84);
        story_4->setObjectName("story_4");
        story_4->setEnabled(false);
        story_4->setGeometry(QRect(300, 660, 1321, 221));
        story_4->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_4->setReadOnly(true);
        story_5 = new QTextEdit(Page84);
        story_5->setObjectName("story_5");
        story_5->setEnabled(false);
        story_5->setGeometry(QRect(300, 660, 1321, 221));
        story_5->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_5->setReadOnly(true);
        story_6 = new QTextEdit(Page84);
        story_6->setObjectName("story_6");
        story_6->setEnabled(false);
        story_6->setGeometry(QRect(300, 660, 1321, 221));
        story_6->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_6->setReadOnly(true);
        story_7 = new QTextEdit(Page84);
        story_7->setObjectName("story_7");
        story_7->setEnabled(false);
        story_7->setGeometry(QRect(300, 660, 1321, 221));
        story_7->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_7->setReadOnly(true);
        story_8 = new QTextEdit(Page84);
        story_8->setObjectName("story_8");
        story_8->setEnabled(false);
        story_8->setGeometry(QRect(300, 660, 1321, 221));
        story_8->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_8->setReadOnly(true);
        p_end = new QPushButton(Page84);
        p_end->setObjectName("p_end");
        p_end->setGeometry(QRect(830, 960, 231, 61));
        p_end->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_end->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));

        retranslateUi(Page84);

        QMetaObject::connectSlotsByName(Page84);
    } // setupUi

    void retranslateUi(QWidget *Page84)
    {
        Page84->setWindowTitle(QCoreApplication::translate("Page84", "Form", nullptr));
        label->setText(QString());
        blur->setText(QString());
        p_next->setText(QCoreApplication::translate("Page84", "Continue", nullptr));
        p_end->setText(QCoreApplication::translate("Page84", "THE END", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page84: public Ui_Page84 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE84_H
