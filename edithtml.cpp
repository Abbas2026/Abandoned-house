#include "edithtml.h"

Qt::Alignment getTextAlignment(const QString &html)
{
    if (html.contains("text-align: center") || html.contains("align=\"center\"")) {
        return Qt::AlignCenter;
    }
    if (html.contains("text-align: right") || html.contains("align=\"right\"")) {
        return Qt::AlignRight;
    }
    return Qt::AlignLeft;
}
QString extractPlainTextFromHtml(const QString &html) {
    QTextDocument doc;
    doc.setHtml(html);
    return doc.toPlainText();
}
