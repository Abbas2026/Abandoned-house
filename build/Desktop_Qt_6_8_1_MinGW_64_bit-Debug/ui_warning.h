/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warning
{
public:
    QLabel *label;
    QPushButton *p_next;
    QTextEdit *textEdit;

    void setupUi(QWidget *Warning)
    {
        if (Warning->objectName().isEmpty())
            Warning->setObjectName("Warning");
        Warning->resize(1920, 1080);
        Warning->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Warning);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("images/warning.jpg")));
        label->setScaledContents(true);
        p_next = new QPushButton(Warning);
        p_next->setObjectName("p_next");
        p_next->setGeometry(QRect(320, 890, 231, 61));
        p_next->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        p_next->setStyleSheet(QString::fromUtf8("font: 24pt \"October Crow\";\n"
"background-color: rgb(255, 0, 0);\n"
"letter-spacing: 2px;\n"
"border:none;\n"
"border-radius:15px;"));
        textEdit = new QTextEdit(Warning);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(153, 320, 681, 511));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(72, 74, 89, 0);\n"
"border: none;\n"
"color: rgb(0, 0, 0);\n"
"font: 34pt \"Haunting Attraction\";"));

        retranslateUi(Warning);

        QMetaObject::connectSlotsByName(Warning);
    } // setupUi

    void retranslateUi(QWidget *Warning)
    {
        Warning->setWindowTitle(QCoreApplication::translate("Warning", "Form", nullptr));
        label->setText(QString());
        p_next->setText(QCoreApplication::translate("Warning", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warning: public Ui_Warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
