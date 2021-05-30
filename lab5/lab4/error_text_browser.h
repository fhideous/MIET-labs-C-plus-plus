#ifndef ERROR_TEXT_BROWSER_H
#define ERROR_TEXT_BROWSER_H

#include <QObject>
#include <QTextBrowser>
#include <QTextEdit>

class error_text_browser: public QTextBrowser
{
public:
    error_text_browser(QWidget*& a) : QTextBrowser(a){}

    void error(const QString &);
};

#endif // ERROR_TEXT_BROWSER_H
