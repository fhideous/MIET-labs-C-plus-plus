#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "professor.h"
#include "JSONReader.h"
#include "Student.h"
#include "Empl.h"
#include "out_data.h"
#include "QString"
#include <QLineEdit>
#include <string>
#include "CSVReader.h"
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


/*
 *Add
 */


void MainWindow::on_AddBut_clicked()
{
    std::string path = name_file.toStdString();
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
    try
    {
        empl.set_year(std::stoi(year));
    }
    catch (std::exception& ex)
    {
        ui->textBrowser->error("Wrong year field");

        return ;
    }
    empl.set_gender(sex);
    OutEmplrs out(path);
    out.print_data(empl);
    ui->textBrowser->append("add in """ +
                            QString::fromStdString(path) +
                            """:\n" +
                            QString(name.c_str())+ ";" +
                            QString(year.c_str()) + ";" +
                            QString(sex.c_str()) + ";");
}

/*
 *Find
 */

void MainWindow::on_pushButton_clicked()
{
    std::vector<Employer> emplrs;
    QString str = ui->lineEdit_3->text();
    std::vector<std::string> substr;
    substr = split(name_file.toStdString(), '.');
    std::string path = name_file.toStdString();
    if (substr.size() != 2)
    {
        ui->textBrowser->error("Wrong reading file");
        return ;
    }
    if (ui->file_type->currentText() == "CSV")
    {
         CSVReader file(path);
         if (!file.is_open())
         {
             ui->textBrowser->error("Wrong reading file");
             return ;
         }
         Employer empl;
         while (file >> empl)
            emplrs.push_back(std::move(empl));
         empl.id_reset();
    }
    else if (ui->file_type->currentText() == "JSON")
    {
       JSONReader file(path);
       if (!file.is_open())
       {
           ui->textBrowser->error("Wrong reading file");
           return ;
       }
       try {
           file >> emplrs;
       } catch (int i) {
           if (i < 0)
               ui->textBrowser->error("Wrong year field");
           else
               ui->textBrowser->error("Json has wrong data");

           return ;
       }
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
//    Employers my_mplrs;

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
