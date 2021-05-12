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
#include "CSVReader.h"
#include "JSONReader.h"
#include "QFileDialog"
#include "lab.h"

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
    std::string path = "/home/fhideous/QT/lab4_app/lab3/1";
    Employer empl;
    std::string name, year, sex;

    if (ui->file_type->currentText() == "CSV")
    {
        CSVReader file(path);
        if (!file.is_open())
        {
            ui->textBrowser->error("Wrong input file");
            return ;
        }
        name = ui->lineEdit_1->text().toStdString();
        year  =(ui->lineEdit_2->text().toStdString());
        sex = ui->comboBox->currentText().toStdString();
        if( year == "" )
        {
            ui->textBrowser->error("Wrong input data");
            return ;
        }
        file.fd_close();
    }
    else
    {
        ui->textBrowser->error("CSV files addition only");
        return ;

    }
    empl.set_name(name);
    empl.set_year(std::stoi(year));
    empl.set_gender(sex);
    OutEmplrs out(path);
//    ui->textBrowser->error(ui->lineEdit_1->text() + ui->lineEdit_2->text());
//    ui->textBrowser->error("Kek" + QString::fromStdString(year) + QString::fromStdString(sex));
    out.print_data(empl);
    ui->textBrowser->append("add in """ +
                            QString::fromStdString(path) +
                            """:\n" +
                            QString(name.c_str())+ ";" +
                            QString(year.c_str()) + ";" +
                            QString(sex.c_str()) + ";");
//ui->textBrowser->error(QString::fromStdString(empl.get_gender()));
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<Employer> emplrs;
    std::string path = "/home/fhideous/QT/lab4_app/lab3/1";
    QString str = ui->lineEdit_3->text();
    std::vector<std::string> substr;
    substr = split(name_file.toStdString(), '.');

    if (substr.back() == "csv")
    {
         CSVReader file(path);

         if (!file.is_open())
         {
             ui->textBrowser->error("Wrong reading file");
             return ;
         }
         while (1)
         {
            Employer empl;
            if (!file.read(empl))
            {
                empl.id_reset();
                break;
            }
            emplrs.push_back(std::move(empl));
         }
    }
    else if (substr.back() == "json")
    {
       path = "/home/fhideous/QT/lab4_app/lab3/1.json";
       JSONReader file(path);
       if (!file.is_open())
       {
           ui->textBrowser->error("Wrong reading file");
           return ;
       }
       emplrs = file.read_all();
    }
    else
    {
        ui->textBrowser->error("Wrong reading file");
        return ;
    }

    size_t i = 0;
    for(auto &n : emplrs)
    {
        if (QString::fromStdString(n.get_name()) == str)
            break ;
        i++;

//        ui->textBrowser->error("kek: " + QString::fromStdString(n.get_gender()));
    }
    if (i < emplrs.size())
    {
        ui->textBrowser->append("Info: \n--------------");
        ui->textBrowser->append("ID: \t\t" + QString::fromStdString(std::to_string(emplrs[i].get_id())));
        ui->textBrowser->append("Name: \t\t" + QString::fromStdString(emplrs[i].get_name()));
        ui->textBrowser->append("Gender: \t\t" + QString::fromStdString(emplrs[i].get_gender()));
        ui->textBrowser->append("Year of birth: \t" + QString::fromStdString(std::to_string(emplrs[i].get_year())));
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

void MainWindow::on_on_browse_clicked_clicked()
{
    name_file = QFileDialog::getOpenFileName(this, tr("Open Text"), "/home/fhideous/QT/fnal4", tr("Text Files (*.csv *.json)"));

}
