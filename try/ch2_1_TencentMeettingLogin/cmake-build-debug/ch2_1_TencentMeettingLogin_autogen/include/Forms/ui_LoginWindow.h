/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(434, 761);
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        pushButton_2 = new QPushButton(LoginWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(LoginWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(400, 336));
        label_2->setMaximumSize(QSize(400, 336));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_4 = new QPushButton(LoginWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(400, 50));
        pushButton_4->setMaximumSize(QSize(400, 50));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(LoginWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(400, 50));
        pushButton_5->setMaximumSize(QSize(400, 50));

        verticalLayout->addWidget(pushButton_5);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        line = new QFrame(LoginWindow);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line);

        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        line_2 = new QFrame(LoginWindow);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        toolButton = new QToolButton(LoginWindow);
        toolButton->setObjectName("toolButton");
        toolButton->setMinimumSize(QSize(60, 80));
        toolButton->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolButton);

        toolButton_2 = new QToolButton(LoginWindow);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setMinimumSize(QSize(60, 80));
        toolButton_2->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(LoginWindow);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setMinimumSize(QSize(60, 80));
        toolButton_3->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\350\247\206\351\242\221\344\274\232\350\256\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "TextLabel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LoginWindow", "\345\212\240\345\205\245\344\274\232\350\256\256", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\345\205\266\344\273\226\347\231\273\351\231\206\346\226\271\345\274\217", nullptr));
        toolButton->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
