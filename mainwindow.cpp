#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employers.h"
#include "out_data.h"
#include "QString"
#include <QLineEdit>
#include <algorithm>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_AddBut_clicked()
{
    Employers emy_mplrs;
    std::string file_0 = "/home/fhideous/lab2/csv.csv";
    std::string file_1 = "/home/fhideous/lab2/1";

    emy_mplrs.set_path_r(file_1);
    emy_mplrs.add_emplrs();

    std::string id  =(ui->lineEdit_0->text().toStdString());
    std::string name = ui->lineEdit_1->text().toStdString();
    std::string year  =(ui->lineEdit_2->text().toStdString());
    std::string sex = ui->comboBox->currentText().toStdString();

    Employer new_empl(stoi(id), name, stoi(year),sex);

    emy_mplrs.add_emplr(new_empl);
    ui->textBrowser->append("add: "+ QString(id.c_str())+" "+ QString(name.c_str())+ " " + QString(year.c_str()) + " " + QString(sex.c_str()) );

    OutEmplrs out(file_1, emy_mplrs.get_emplrs());
    out.print_data();

}

void MainWindow::on_pushButton_clicked()
{
    std::string file_0 = "/home/fhideous/lab2/1";
    QString str = ui->lineEdit_3->text();


    std::vector<Employer> empls;
    Employers my_mplrs;
    Employer emp;

    my_mplrs.set_path_r(file_0);
    my_mplrs.add_emplrs();
    empls = my_mplrs.get_emplrs();

    int i = 0;
    for(auto &n : empls)
    {
        if (QString::fromStdString(n.get_name()) == str)
            break ;
        i++;
    }
    if (i < empls.size())
    {
        emp = empls[i];

        ui->textBrowser->setText(QString::fromStdString(std::to_string(emp.get_id())));
        ui->textBrowser->append(QString::fromStdString(emp.get_name()));
        ui->textBrowser->append(QString::fromStdString(emp.get_gender()));
        ui->textBrowser->append(QString::fromStdString(std::to_string(emp.get_year())));

    }
}
