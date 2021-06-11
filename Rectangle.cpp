#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height):x(x),y(y),width(width),height(height)
{

}

void Rectangle::draw(QPainter &qp) const
{
    qp.drawRect(x,y,width,height);
}

bool Rectangle::mouseFlag(QPoint& point) {
    if (x <= point.x() && point.x() <= (x+width) &&
        y <= point.y() && point.y() <= (y+height))
        flag = 1;
    else
        flag = 0;
    return flag;
}

void Rectangle::move_figure(QPoint a){
    x+=a.x();
    y+=a.y();
}

std::string Rectangle::print() const {
    return "Rectangle:\nWidth  = " + std::to_string(width) + "\nHeight = " + std::to_string(height);
}

