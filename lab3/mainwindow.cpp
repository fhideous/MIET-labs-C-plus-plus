#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employers.h"
#include "out_data.h"
#include "QString"
#include <QLineEdit>
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
    std::string file_1 = "/home/fhideous//lab2/lab3/1";
    static bool is_first = true;

    if(emy_mplrs.set_path_r(file_1))
    {
        ui->textBrowser->append("Wrong input file");
        return ;
    }
    if (is_first)
    {
        emy_mplrs.add_emplrs();
        is_first = 0;
    }
    std::string name = ui->lineEdit_1->text().toStdString();
    std::string year  =(ui->lineEdit_2->text().toStdString());
    std::string sex = ui->comboBox->currentText().toStdString();

    std::vector<std::string> data = {name, year, sex};
    Employer new_empl(data);
    OutEmplrs out(file_1);
    out.print_data(new_empl);

    emy_mplrs.add_emplr(std::move(new_empl));
    ui->textBrowser->append("add in """ +
                            QString::fromStdString(emy_mplrs.get_path()) +
                            """:\n" +
                            QString(name.c_str())+ ";" +
                            QString(year.c_str()) + ";" +
                            QString(sex.c_str()) + ";");

}

void MainWindow::on_pushButton_clicked()
{
    std::string file_0 = "/home/fhideous/lab2/lab3/1";
    QString str = ui->lineEdit_3->text();

    std::vector<Employer> empls;
    Employers my_mplrs;

    if (my_mplrs.set_path_r(file_0))
    {
        ui->textBrowser->append("Wrong reading file");
        return ;
    }
    my_mplrs.add_emplrs();
    empls = my_mplrs.get_emplrs();

    int i = 0;
    for(auto &n : empls)
    {
        if (QString::fromStdString(n.get_name()) == str)
            break ;
        i++;
    }

    if (i < (int)empls.size())
    {
        Employer emp = std::move(empls[i]);
        ui->textBrowser->append("Info: \n--------------");
        ui->textBrowser->append("ID: \t\t" + QString::fromStdString(std::to_string(emp.get_id())));
        ui->textBrowser->append("Name: \t\t" + QString::fromStdString(emp.get_name()));
        ui->textBrowser->append("Gender: \t\t" + QString::fromStdString(emp.get_gender()));
        ui->textBrowser->append("Year of birth: \t" + QString::fromStdString(std::to_string(emp.get_year())));
        ui->textBrowser->append("--------------");
    }
    else
        ui->textBrowser->append("Name does not found");
}
