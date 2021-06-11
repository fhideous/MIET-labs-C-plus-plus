#include "PainterWidget.h"
#include "utility"
#include <QMenu>


void MyWidget::AddFigure(Figure* fg)
{
    figures.push_back(std::unique_ptr<Figure>(fg));
    update();
}

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(1);
}
void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (const auto& i : figures) {
        if (i->GetFlag()) {
            painter.setPen(Qt::black);
            painter.setBrush(Qt::red);
        }
        else
        {
            painter.setPen(Qt::black);
            painter.setBrush(Qt::NoBrush);
        }
        i->draw(painter);

        if(i->GetFlag()){
            QRect a(click+QPoint{20,0},QSize(200,200));
            painter.setPen(Qt::black);
            painter.drawText(a,Qt::TextWordWrap,i->print().c_str());
        }
    }
    update();
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {
    QPoint point(event->pos());
    for (const auto& i: figures)
    {
        if (i->mouseFlag(point))
        {
            update();
            click=event->pos();
        }
            update();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    for (const auto& i: figures)
    {
        if (i->press_move_dx != nullptr)
        {
            i->move_figure(event->pos() - *i->press_move_dx);
            delete i->press_move_dx;
            i->press_move_dx = nullptr;
        }
    }
    mouseMoveEvent(event);
    update();
}


void MyWidget::mousePressEvent(QMouseEvent* event) {
    QPoint point(event->pos());

    if (event->buttons() == Qt::RightButton)
    {
        for (const auto& i: figures)
        {
            if (i->mouseFlag(point))
            {
                QMenu * menu = new QMenu(this);
                QAction* delete_figure = new QAction("&Delete figure",this);
                connect(delete_figure,&QAction::triggered,this,&MyWidget::delete_figure);
                menu->addAction(delete_figure);
                menu->exec(QCursor::pos());
            }
        }
    }
    if (event->buttons() == Qt::LeftButton)
    {
        for (const auto& i: figures)
        {
            if (i->mouseFlag(point))
            {
                if (i->press_move_dx == nullptr)
                    i->press_move_dx = new QPoint(event->pos());
            }
        }
    }
    update();
}

void MyWidget::delete_figure()
{
    std::list<std::unique_ptr<Figure>>::iterator it;
    for (it = figures.begin(); it != figures.end(); ++it)
    {
        if (it->get()->GetFlag())
        {
            figures.erase(it);
            break;
        }
    }
}

MyWidget::~MyWidget()
{
}
