#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employers.h"
#include "professor.h"
#include "Student.h"
#include "Empl.h"
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
        ui->textBrowser->error("Wrong input file");
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
    if( year == "" )
    {
        ui->textBrowser->error("Wrong input data");
        return ;
    }
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
    Employers my_mplrs;

    if (my_mplrs.set_path_r(file_0))
    {
        ui->textBrowser->error("Wrong reading file");
        return ;
    }
    my_mplrs.add_emplrs();
//    empls = my_mplrs.get_emplrs();

    int i = 0;
    for(auto &n : my_mplrs.get_emplrs())
    {
        if (QString::fromStdString(n.get_name()) == str)
            break ;
        i++;
    }

    if (i < my_mplrs.get_emplrs().size())
    {
        Employer emp = std::move(my_mplrs.get_emplrs()[i]);
        ui->textBrowser->append("Info: \n--------------");
        ui->textBrowser->append("ID: \t\t" + QString::fromStdString(std::to_string(emp.get_id())));
        ui->textBrowser->append("Name: \t\t" + QString::fromStdString(emp.get_name()));
        ui->textBrowser->append("Gender: \t\t" + QString::fromStdString(emp.get_gender()));
        ui->textBrowser->append("Year of birth: \t" + QString::fromStdString(std::to_string(emp.get_year())));
        ui->textBrowser->append("--------------");
    }
    else
        ui->textBrowser->error("Name does not found");
}

void MainWindow::on_Info_clicked()
{
    std::vector<Employer*> emplrs;
    Employers my_mplrs;

    std::vector<std::string> data = {"Vlad", "2001", "MALE"};
    Empl emp1("120400",data);
    data[0] = "Igor";
    Student stud("IVT", data);
    data[0] = "Sonya";
    data[2] = "FEMALE";
    Professor prof("Math", data);
    emplrs.push_back(&emp1);
    emplrs.push_back(&stud);
    emplrs.push_back(&prof);
    for(auto &n :emplrs)
        ui->textBrowser->append(QString::fromStdString(n->repr()));
    ui->textBrowser->error("Error");
}
