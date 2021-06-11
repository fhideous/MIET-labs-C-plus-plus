#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include "QPainter"
class Circle : public Figure
{
public:
    Circle(QPointF centre,qreal r);

    void draw(QPainter& qp)const override;
    bool mouseFlag(QPoint& point) override;
    std::string print() const override;
    void move_figure(QPoint a) override;

private:
    QPointF centre;
    qreal r;
};

#endif // CIRCLE_H
