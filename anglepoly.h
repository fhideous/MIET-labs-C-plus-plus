#ifndef ANGLEPOLY_H
#define ANGLEPOLY_H

#include "figure.h"

template <size_t N>
class AnglePoly : public Figure
{
public:
    AnglePoly() = default ;
    AnglePoly(const std::array<QPoint, N>& src):
        map(src){}

    virtual void draw(QPainter &P) override
    {
        P.setPen(Qt::black);
        for (int i = 0; i < N; i++)
            P.drawLine(map[i], map[(i + 1) % N]);
    }
protected:
    std::array <QPoint, N> map;
};

#endif // ANGLEPOLY_H
