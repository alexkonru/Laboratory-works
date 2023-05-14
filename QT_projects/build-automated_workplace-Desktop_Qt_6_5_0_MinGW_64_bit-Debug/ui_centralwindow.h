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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CentralWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *pushButton;

    void setupUi(QDialog *CentralWindow)
    {
        if (CentralWindow->objectName().isEmpty())
            CentralWindow->setObjectName("CentralWindow");
        CentralWindow->resize(721, 611);
        verticalLayout = new QVBoxLayout(CentralWindow);
        verticalLayout->setObjectName("verticalLayout");
        button1 = new QPushButton(CentralWindow);
        button1->setObjectName("button1");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);
        button1->setIconSize(QSize(20, 100));

        verticalLayout->addWidget(button1);

        button2 = new QPushButton(CentralWindow);
        button2->setObjectName("button2");
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);
        button2->setIconSize(QSize(20, 100));

        verticalLayout->addWidget(button2);

        button3 = new QPushButton(CentralWindow);
        button3->setObjectName("button3");
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);
        button3->setIconSize(QSize(20, 100));

        verticalLayout->addWidget(button3);

        pushButton = new QPushButton(CentralWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(CentralWindow);

        QMetaObject::connectSlotsByName(CentralWindow);
    } // setupUi

    void retranslateUi(QDialog *CentralWindow)
    {
        CentralWindow->setWindowTitle(QCoreApplication::translate("CentralWindow", "Dialog", nullptr));
        button1->setText(QCoreApplication::translate("CentralWindow", "\320\222\320\265\320\273\320\276\321\201\320\270\320\277\320\265\320\264\321\213", nullptr));
        button2->setText(QCoreApplication::translate("CentralWindow", "\320\220\320\272\321\201\320\265\321\201\321\201\321\203\320\260\321\200\321\213", nullptr));
        button3->setText(QCoreApplication::translate("CentralWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("CentralWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentralWindow: public Ui_CentralWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWINDOW_H
