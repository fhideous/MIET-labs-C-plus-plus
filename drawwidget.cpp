#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{

}

DrawWidget::~DrawWidget()
{
    for(auto &n: to_paint)
        delete (n);
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
