#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
public:
    Circle() = default;
    Circle(const QPoint&, int, int);
    virtual void draw(QPainter &) override;

protected:
    int width;
    int length;
    QPoint center;

};

#endif // CIRCLE_H
