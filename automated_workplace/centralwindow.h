#ifndef CENTRALWINDOW_H
#define CENTRALWINDOW_H

#include <QDialog>

namespace Ui {
class CentralWindow;
}

class CentralWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CentralWindow(QWidget *parent = nullptr);
    ~CentralWindow();

private:
    Ui::CentralWindow *ui;
};

#endif // CENTRALWINDOW_H
