#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{

}

DrawWidget::~DrawWidget()
{
    for(int i = to_paint.size() - 1; i >= 0; --i)
    {
        delete (to_paint[i]);
        to_paint.erase(to_paint.begin() + i);
    }
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (const auto i:to_paint)
    {
        i->draw(painter);
    }

}

void DrawWidget::setFigures(std::vector<Figure*>&& src)
{
    to_paint = src;
}
