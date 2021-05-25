#include "circle.h"

Circle::Circle(const QPoint &cent, int x, int y):
    width(x), length(y), center(cent)
{

}

void Circle::draw(QPainter &P)
{
    P.setPen(Qt::black);
    P.drawEllipse(center, width, length);
}
