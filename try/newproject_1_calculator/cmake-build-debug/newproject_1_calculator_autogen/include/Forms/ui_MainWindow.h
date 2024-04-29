/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *btn_add;
    QPushButton *btn_point;
    QPushButton *btn_deleate;
    QPushButton *btn2;
    QPushButton *btn7;
    QPushButton *btn_divide;
    QPushButton *btn9;
    QPushButton *btn_multiply;
    QPushButton *btn_ac;
    QPushButton *btn8;
    QPushButton *btn1;
    QPushButton *btn;
    QPushButton *btn_result;
    QPushButton *btn4;
    QPushButton *btn3;
    QPushButton *btn6;
    QPushButton *btn_unknown;
    QPushButton *btn_subtract;
    QPushButton *btn0;
    QPushButton *btn5;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(300, 425);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(300, 425));
        MainWindow->setMaximumSize(QSize(300, 425));
        MainWindow->setBaseSize(QSize(400, 600));
        widget = new QWidget(MainWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 304, 435));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(300, 50));
        label->setMaximumSize(QSize(300, 50));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(116,116,116);"));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        btn_add = new QPushButton(widget);
        btn_add->setObjectName("btn_add");
        btn_add->setMinimumSize(QSize(75, 75));
        btn_add->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_add, 3, 3, 1, 1);

        btn_point = new QPushButton(widget);
        btn_point->setObjectName("btn_point");
        btn_point->setMinimumSize(QSize(75, 75));
        btn_point->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_point, 4, 2, 1, 1);

        btn_deleate = new QPushButton(widget);
        btn_deleate->setObjectName("btn_deleate");
        btn_deleate->setMinimumSize(QSize(75, 75));
        btn_deleate->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_deleate, 0, 1, 1, 1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName("btn2");
        btn2->setMinimumSize(QSize(75, 75));
        btn2->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn2, 1, 1, 1, 1);

        btn7 = new QPushButton(widget);
        btn7->setObjectName("btn7");
        btn7->setMinimumSize(QSize(75, 75));
        btn7->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn7, 3, 0, 1, 1);

        btn_divide = new QPushButton(widget);
        btn_divide->setObjectName("btn_divide");
        btn_divide->setMinimumSize(QSize(75, 75));
        btn_divide->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_divide, 0, 3, 1, 1);

        btn9 = new QPushButton(widget);
        btn9->setObjectName("btn9");
        btn9->setMinimumSize(QSize(75, 75));
        btn9->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn9, 3, 2, 1, 1);

        btn_multiply = new QPushButton(widget);
        btn_multiply->setObjectName("btn_multiply");
        btn_multiply->setMinimumSize(QSize(75, 75));
        btn_multiply->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_multiply, 1, 3, 1, 1);

        btn_ac = new QPushButton(widget);
        btn_ac->setObjectName("btn_ac");
        btn_ac->setMinimumSize(QSize(75, 75));
        btn_ac->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_ac, 0, 2, 1, 1);

        btn8 = new QPushButton(widget);
        btn8->setObjectName("btn8");
        btn8->setMinimumSize(QSize(75, 75));
        btn8->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn8, 3, 1, 1, 1);

        btn1 = new QPushButton(widget);
        btn1->setObjectName("btn1");
        btn1->setMinimumSize(QSize(75, 75));
        btn1->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn1, 1, 0, 1, 1);

        btn = new QPushButton(widget);
        btn->setObjectName("btn");
        btn->setMinimumSize(QSize(75, 75));
        btn->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn, 0, 0, 1, 1);

        btn_result = new QPushButton(widget);
        btn_result->setObjectName("btn_result");
        btn_result->setMinimumSize(QSize(75, 75));
        btn_result->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_result, 4, 3, 1, 1);

        btn4 = new QPushButton(widget);
        btn4->setObjectName("btn4");
        btn4->setMinimumSize(QSize(75, 75));
        btn4->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn4, 2, 0, 1, 1);

        btn3 = new QPushButton(widget);
        btn3->setObjectName("btn3");
        btn3->setMinimumSize(QSize(75, 75));
        btn3->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn3, 1, 2, 1, 1);

        btn6 = new QPushButton(widget);
        btn6->setObjectName("btn6");
        btn6->setMinimumSize(QSize(75, 75));
        btn6->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn6, 2, 2, 1, 1);

        btn_unknown = new QPushButton(widget);
        btn_unknown->setObjectName("btn_unknown");
        btn_unknown->setMinimumSize(QSize(75, 75));
        btn_unknown->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_unknown, 4, 0, 1, 1);

        btn_subtract = new QPushButton(widget);
        btn_subtract->setObjectName("btn_subtract");
        btn_subtract->setMinimumSize(QSize(75, 75));
        btn_subtract->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn_subtract, 2, 3, 1, 1);

        btn0 = new QPushButton(widget);
        btn0->setObjectName("btn0");
        btn0->setMinimumSize(QSize(75, 75));
        btn0->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn0, 4, 1, 1, 1);

        btn5 = new QPushButton(widget);
        btn5->setObjectName("btn5");
        btn5->setMinimumSize(QSize(75, 75));
        btn5->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(btn5, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btn_deleate->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btn_ac->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        btn_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_unknown->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        btn_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
