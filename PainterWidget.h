#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <iostream>
#include <memory>
#include <list>
#include <Figure.h>
#include "functional"
class MyWidget : public QWidget
{
    Q_OBJECT
private:
    std::list<std::unique_ptr<Figure>> figures;
    QPoint click;
public:
    explicit MyWidget(QWidget *parent = nullptr);

    void AddFigure(Figure* fg);
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void delete_figure();

    ~MyWidget()override;

signals:

public slots:
};

#endif // PAINTERWIDGET_H
