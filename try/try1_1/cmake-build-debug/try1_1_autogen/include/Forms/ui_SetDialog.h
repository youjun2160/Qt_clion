/********************************************************************************
** Form generated from reading UI file 'setdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDIALOG_H
#define UI_SETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetDialog
{
public:
    QPushButton *btnAdd;

    void setupUi(QDialog *SetDialog)
    {
        if (SetDialog->objectName().isEmpty())
            SetDialog->setObjectName("SetDialog");
        SetDialog->resize(400, 300);
        btnAdd = new QPushButton(SetDialog);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(160, 120, 75, 24));

        retranslateUi(SetDialog);

        QMetaObject::connectSlotsByName(SetDialog);
    } // setupUi

    void retranslateUi(QDialog *SetDialog)
    {
        SetDialog->setWindowTitle(QCoreApplication::translate("SetDialog", "SetDialog", nullptr));
        btnAdd->setText(QCoreApplication::translate("SetDialog", "\345\242\236\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetDialog: public Ui_SetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDIALOG_H
