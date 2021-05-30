
#include "error_text_browser.h"


void error_text_browser::error(const QString &str)
{
    QColor old_color = textColor();
    setTextColor(QColor(255, 0, 0));
    append(str);
    setTextColor(old_color);
}
