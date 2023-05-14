#ifndef CENTRALWINDOW_H
#define CENTRALWINDOW_H

#include <QDialog>
#include "firstwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"

namespace Ui {
class CentralWindow;
}

class CentralWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CentralWindow(QWidget *parent = nullptr);
    ~CentralWindow();

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_pushButton_clicked();

private:
    Ui::CentralWindow *ui;
    FirstWindow *window1;
    SecondWindow *window2;
    ThirdWindow *window3;
};

#endif // CENTRALWINDOW_H
