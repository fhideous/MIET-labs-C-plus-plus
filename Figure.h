#ifndef FIGURE_H
#define FIGURE_H
#include "QPainter"

class Figure
{
public:
    Figure();
public:
    bool GetFlag() const ;
    virtual void draw(QPainter& qp)const;
    virtual bool mouseFlag(QPoint& point) = 0;
    virtual std::string print() const = 0;
    virtual void move_figure(QPoint a) = 0;

    QPoint *press_move_dx;


    virtual ~Figure();

protected:
    bool flag;
};

#endif // FIGURE_H
