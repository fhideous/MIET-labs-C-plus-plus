#include "Circle.h"


Circle::Circle(QPointF centre,qreal r):centre(centre),r(r)
{

}

void Circle::draw(QPainter& qp) const
{
    qp.drawEllipse(centre,r,r);
}

bool Circle::mouseFlag(QPoint& point) {
    if (r * r >= (point.x() - centre.x()) * (point.x() - centre.x()) + (point.y() - centre.y()) * (point.y() - centre.y()))
        flag = 1;
    else
        flag = 0;
    return flag;
}

void Circle::move_figure(QPoint a){
    centre.rx() += a.x();
    centre.ry() += a.y();
}

std::string Circle::print() const {
    return "Circle:\nCenter(" + std::to_string((int)centre.x()) + ";" + std::to_string((int)centre.x()) + ")\nRadius = " + std::to_string((int)r);
}
