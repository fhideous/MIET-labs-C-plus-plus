#ifndef FIGURE_H
#define FIGURE_H

#include <QPoint>
#include <QColor>
#include <QPainter>

class Figure
{
public:
    Figure();
    virtual ~Figure() {};
    virtual void draw(QPainter&) = 0;
};

#endif // FIGURE_H
