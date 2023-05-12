#include "centralwindow.h"
#include "ui_centralwindow.h"

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
