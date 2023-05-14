#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "centralwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}

