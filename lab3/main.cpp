
//#include "../hdrs/lab.h"
//#include "../hdrs/employers.h"
//#include "../hdrs/out_data.h"

#include "mainwindow.h"
#include<QApplication>
#include <QTabletEvent>
#include "lab.h"
#include "employers.h"
#include "out_data.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
