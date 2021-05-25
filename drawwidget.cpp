#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{

}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (const auto i:to_paint)
    {
        i->draw(painter);
    }
}

void DrawWidget::setFigures(const std::vector<Figure*>& src)
{
    to_paint = std::move(src);
}
