/********************************************************************************
** Form generated from reading UI file 'centralwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTRALWINDOW_H
#define UI_CENTRALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CentralWindow
{
public:

    void setupUi(QDialog *CentralWindow)
    {
        if (CentralWindow->objectName().isEmpty())
            CentralWindow->setObjectName("CentralWindow");
        CentralWindow->resize(721, 611);

        retranslateUi(CentralWindow);

        QMetaObject::connectSlotsByName(CentralWindow);
    } // setupUi

    void retranslateUi(QDialog *CentralWindow)
    {
        CentralWindow->setWindowTitle(QCoreApplication::translate("CentralWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentralWindow: public Ui_CentralWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWINDOW_H
