/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QPushButton *p_next;
    QTextEdit *story;
    QLabel *label;
    QTextEdit *story_2;
    QTextEdit *story_3;
    QTextEdit *story_4;
    QTextEdit *story_5;
    QTextEdit *story_6;
    QTextEdit *story_7;
    QTextEdit *story_8;
    QTextEdit *story_9;
    QTextEdit *story_10;
    QPushButton *left_btn;
    QPushButton *right_btn;
    QTextEdit *story_1;
    QLabel *blur;

    void setupUi(QWidget *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName("start");
        start->resize(1920, 1080);
        start->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        p_next = new QPushButton(start);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 980, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story = new QTextEdit(start);
        story->setObjectName("story");
        story->setEnabled(false);
        story->setGeometry(QRect(300, 660, 1321, 221));
        story->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story->setReadOnly(true);
        label = new QLabel(start);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/rr.jpg")));
        label->setScaledContents(true);
        story_2 = new QTextEdit(start);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);
        story_3 = new QTextEdit(start);
        story_3->setObjectName("story_3");
        story_3->setEnabled(false);
        story_3->setGeometry(QRect(300, 660, 1321, 221));
        story_3->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_3->setReadOnly(true);
        story_4 = new QTextEdit(start);
        story_4->setObjectName("story_4");
        story_4->setEnabled(false);
        story_4->setGeometry(QRect(300, 660, 1321, 221));
        story_4->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_4->setReadOnly(true);
        story_5 = new QTextEdit(start);
        story_5->setObjectName("story_5");
        story_5->setEnabled(false);
        story_5->setGeometry(QRect(300, 660, 1321, 221));
        story_5->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_5->setReadOnly(true);
        story_6 = new QTextEdit(start);
        story_6->setObjectName("story_6");
        story_6->setEnabled(false);
        story_6->setGeometry(QRect(300, 660, 1321, 221));
        story_6->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_6->setReadOnly(true);
        story_7 = new QTextEdit(start);
        story_7->setObjectName("story_7");
        story_7->setEnabled(false);
        story_7->setGeometry(QRect(300, 660, 1321, 221));
        story_7->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_7->setReadOnly(true);
        story_8 = new QTextEdit(start);
        story_8->setObjectName("story_8");
        story_8->setEnabled(false);
        story_8->setGeometry(QRect(300, 660, 1321, 221));
        story_8->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_8->setReadOnly(true);
        story_9 = new QTextEdit(start);
        story_9->setObjectName("story_9");
        story_9->setEnabled(false);
        story_9->setGeometry(QRect(300, 660, 1321, 221));
        story_9->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_9->setReadOnly(true);
        story_10 = new QTextEdit(start);
        story_10->setObjectName("story_10");
        story_10->setEnabled(false);
        story_10->setGeometry(QRect(300, 660, 1321, 221));
        story_10->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_10->setReadOnly(true);
        left_btn = new QPushButton(start);
        left_btn->setObjectName("left_btn");
        left_btn->setGeometry(QRect(150, 980, 521, 61));
        left_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        left_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        right_btn = new QPushButton(start);
        right_btn->setObjectName("right_btn");
        right_btn->setGeometry(QRect(1270, 980, 521, 61));
        right_btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        right_btn->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_1 = new QTextEdit(start);
        story_1->setObjectName("story_1");
        story_1->setEnabled(false);
        story_1->setGeometry(QRect(300, 660, 1321, 221));
        story_1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        story_1->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_1->setReadOnly(true);
        blur = new QLabel(start);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        story->raise();
        story_2->raise();
        story_3->raise();
        story_4->raise();
        story_5->raise();
        story_6->raise();
        story_7->raise();
        story_8->raise();
        story_9->raise();
        story_10->raise();
        story_1->raise();
        label->raise();
        blur->raise();
        right_btn->raise();
        p_next->raise();
        left_btn->raise();

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QWidget *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "Abandoned house", nullptr));
        p_next->setText(QCoreApplication::translate("start", "Continue", nullptr));
        label->setText(QString());
        left_btn->setText(QCoreApplication::translate("start", "no thanks", nullptr));
        right_btn->setText(QCoreApplication::translate("start", "I\342\200\231ll do it", nullptr));
        blur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
