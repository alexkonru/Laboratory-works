#include "centralwindow.h"
#include "ui_centralwindow.h"
#include "mainwindow.h"

CentralWindow::CentralWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CentralWindow)
{
    ui->setupUi(this);
}

CentralWindow::~CentralWindow()
{
    delete ui;
}

void CentralWindow::on_button1_clicked()
{
    close();
    window1 = new FirstWindow(this);
    window1->show();
}


void CentralWindow::on_button2_clicked()
{
    close();
    window2 = new SecondWindow(this);
    window2->show();
}


void CentralWindow::on_button3_clicked()
{
    close();
    window3 = new ThirdWindow(this);
    window3->show();
}


void CentralWindow::on_pushButton_clicked()
{
    close();
    MainWindow *window4 = new MainWindow(this);
    window4->show();
}

