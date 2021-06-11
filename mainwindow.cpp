#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    ui->widget->AddFigure(new Circle(QPointF{60, 40},284));
    ui->widget->AddFigure(new Rectangle(110,300,400,110));
    ui->widget->AddFigure(new Triangle({QPointF{100, 250},QPointF{800,600},QPointF{600,50}}));
}
