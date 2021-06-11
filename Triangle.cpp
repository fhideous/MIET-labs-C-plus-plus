#include "Triangle.h"
#include "algorithm"
#include "utility"
#include <cmath>

Triangle::Triangle(std::vector<QPointF> digits):digits(std::move(digits))
{

}

void Triangle::draw(QPainter& qp) const
{
    qp.drawConvexPolygon(&digits[0],static_cast<int>(digits.size()));
}

bool Triangle::mouseFlag(QPoint& point)
{
    flag = false;
    size_t j = digits.size() - 1;
    for (size_t i = 0; i < digits.size(); i++) {
        if ( ((digits[i].y() < point.y() && digits[j].y() >= point.y()) || (digits[j].y() < point.y() && digits[i].y() >= point.y())) &&
             (digits[i].x() + (point.y() - digits[i].y()) / (digits[j].y() - digits[i].y()) * (digits[j].x() - digits[i].x()) < point.x()) )
            flag = !flag;
        j = i;
    }
        return flag;
}

void Triangle::move_figure(QPoint a){
    for(size_t i=0;i<digits.size();++i){
       digits[i].rx()+=a.x();
       digits[i].ry()+=a.y();
    }
}

std::string Triangle::print() const {
    std::string Points;

    for(size_t i=0;i<digits.size();++i){
        Points += "(" + std::to_string((int)digits[i].x()) + ";" + std::to_string((int)digits[i].y()) + ")";
    }
    return "Triangle:\nPoints : " + Points;
}


