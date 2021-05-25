#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<Figure*> vec;
    Figure *triangle = new AnglePoly<3>({QPoint{100, 400}, QPoint{30, 100}, QPoint{500, 99}});
    vec.push_back(triangle);

    Figure *square = new AnglePoly<4>({QPoint{130, 140}, QPoint{130, 200}, QPoint{200, 200}, QPoint{200, 140}});
    vec.push_back(square);

    Figure *circle = new Circle(QPoint{100, 400}, 90, 90);
    vec.push_back(circle);

    ui->DrawBoard->setFigures(vec);
}

MainWindow::~MainWindow()
{
    delete ui;
}

