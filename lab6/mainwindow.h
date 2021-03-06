#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_AddBut_clicked();

    void on_pushButton_clicked();

    void on_Info_clicked();

    void on_on_browse_clicked_clicked();

private:
        QString name_file;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
