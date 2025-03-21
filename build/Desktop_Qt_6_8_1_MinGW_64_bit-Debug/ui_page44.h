/********************************************************************************
** Form generated from reading UI file 'page44.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE44_H
#define UI_PAGE44_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page44
{
public:
    QLabel *label;
    QLabel *blur;
    QPushButton *p_next;
    QTextEdit *story_0;
    QTextEdit *story_1;
    QTextEdit *story_2;

    void setupUi(QWidget *Page44)
    {
        if (Page44->objectName().isEmpty())
            Page44->setObjectName("Page44");
        Page44->resize(1920, 1080);
        Page44->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"\n"
""));
        label = new QLabel(Page44);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/44.jpg")));
        label->setScaledContents(true);
        blur = new QLabel(Page44);
        blur->setObjectName("blur");
        blur->setGeometry(QRect(0, 0, 1920, 1080));
        p_next = new QPushButton(Page44);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(1560, 980, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        story_0 = new QTextEdit(Page44);
        story_0->setObjectName("story_0");
        story_0->setEnabled(false);
        story_0->setGeometry(QRect(300, 660, 1321, 221));
        story_0->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_0->setReadOnly(true);
        story_1 = new QTextEdit(Page44);
        story_1->setObjectName("story_1");
        story_1->setEnabled(false);
        story_1->setGeometry(QRect(300, 660, 1321, 221));
        story_1->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_1->setReadOnly(true);
        story_2 = new QTextEdit(Page44);
        story_2->setObjectName("story_2");
        story_2->setEnabled(false);
        story_2->setGeometry(QRect(300, 660, 1321, 221));
        story_2->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Amatic SC\";\n"
"background-color: rgba(72, 74, 89, 0);\n"
""));
        story_2->setReadOnly(true);

        retranslateUi(Page44);

        QMetaObject::connectSlotsByName(Page44);
    } // setupUi

    void retranslateUi(QWidget *Page44)
    {
        Page44->setWindowTitle(QCoreApplication::translate("Page44", "Form", nullptr));
        label->setText(QString());
        blur->setText(QString());
        p_next->setText(QCoreApplication::translate("Page44", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page44: public Ui_Page44 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE44_H
