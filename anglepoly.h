#ifndef ANGLEPOLY_H
#define ANGLEPOLY_H

#include "figure.h"

template <size_t N>
class AnglePoly : public Figure
{
public:
    AnglePoly() = default ;
    AnglePoly(const std::array<QPoint, N>& src):
        arr(src){}

    virtual void draw(QPainter &P) override
    {
        P.setPen(Qt::black);
        for (int i = 0; i < N; i++)
            P.drawLine(arr[i], arr[(i + 1) % N]);
    }
protected:
    std::array <QPoint, N> arr;
};

#endif // ANGLEPOLY_H
