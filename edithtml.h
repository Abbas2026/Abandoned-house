#ifndef EDITHTML_H
#define EDITHTML_H

#include <QWidget>
#include <QTextEdit>
Qt::Alignment getTextAlignment(const QString &html);
QString extractPlainTextFromHtml(const QString &html);

#endif // EDITHTML_H
