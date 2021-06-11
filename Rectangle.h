#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
class Rectangle : public Figure
{
public:
    Rectangle(int x, int y, int width, int height);

    void draw(QPainter& qp)const override;
    bool mouseFlag(QPoint& point) override;
    std::string print() const override ;
    void move_figure(QPoint a) override;

private:
    int x,y,width,height;
};

#endif // RECTANGLE_H
