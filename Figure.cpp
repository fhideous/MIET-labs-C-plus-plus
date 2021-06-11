#include "Figure.h"



Figure::Figure() : press_move_dx(nullptr)
{

}

bool Figure::GetFlag() const {
    return flag;
}

void Figure::draw(QPainter &qp) const
{
    qp.drawLine(0,0,100,100);
}

Figure::~Figure()
{

}
