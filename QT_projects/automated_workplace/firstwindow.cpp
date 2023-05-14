#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "centralwindow.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}

