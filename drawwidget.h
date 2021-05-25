#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include "figure.h"

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setFigures(const std::vector<Figure*>&);

signals:

protected:
    std::vector<Figure*> to_paint;

};

#endif // DRAWWIDGET_H
