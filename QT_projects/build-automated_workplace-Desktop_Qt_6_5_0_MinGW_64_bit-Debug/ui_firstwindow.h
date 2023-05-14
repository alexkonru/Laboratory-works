/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FirstWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *FirstWindow)
    {
        if (FirstWindow->objectName().isEmpty())
            FirstWindow->setObjectName("FirstWindow");
        FirstWindow->resize(609, 516);
        verticalLayout = new QVBoxLayout(FirstWindow);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(FirstWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(FirstWindow);

        QMetaObject::connectSlotsByName(FirstWindow);
    } // setupUi

    void retranslateUi(QDialog *FirstWindow)
    {
        FirstWindow->setWindowTitle(QCoreApplication::translate("FirstWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FirstWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstWindow: public Ui_FirstWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
