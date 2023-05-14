/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ThirdWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *ThirdWindow)
    {
        if (ThirdWindow->objectName().isEmpty())
            ThirdWindow->setObjectName("ThirdWindow");
        ThirdWindow->resize(614, 502);
        verticalLayout = new QVBoxLayout(ThirdWindow);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(ThirdWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(ThirdWindow);

        QMetaObject::connectSlotsByName(ThirdWindow);
    } // setupUi

    void retranslateUi(QDialog *ThirdWindow)
    {
        ThirdWindow->setWindowTitle(QCoreApplication::translate("ThirdWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ThirdWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdWindow: public Ui_ThirdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
