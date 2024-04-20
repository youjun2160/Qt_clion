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
    QPushButton *btnSet;
    QLabel *label;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_logo;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnWechat_login;
    QPushButton *btnJoin;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolBtnPhoneNumber;
    QToolButton *toolBtnEnpriseWechat;
    QToolButton *toolBtnSSO;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(434, 761);
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSet = new QPushButton(LoginWindow);
        btnSet->setObjectName("btnSet");
        btnSet->setMinimumSize(QSize(32, 32));
        btnSet->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnSet);

        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        btnMin = new QPushButton(LoginWindow);
        btnMin->setObjectName("btnMin");
        btnMin->setMinimumSize(QSize(32, 32));
        btnMin->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnMin);

        btnClose = new QPushButton(LoginWindow);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(32, 32));
        btnClose->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_logo = new QLabel(LoginWindow);
        label_logo->setObjectName("label_logo");
        label_logo->setMinimumSize(QSize(400, 336));
        label_logo->setMaximumSize(QSize(400, 336));

        horizontalLayout_4->addWidget(label_logo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnWechat_login = new QPushButton(LoginWindow);
        btnWechat_login->setObjectName("btnWechat_login");
        btnWechat_login->setMinimumSize(QSize(400, 50));
        btnWechat_login->setMaximumSize(QSize(400, 50));

        verticalLayout->addWidget(btnWechat_login);

        btnJoin = new QPushButton(LoginWindow);
        btnJoin->setObjectName("btnJoin");
        btnJoin->setMinimumSize(QSize(400, 50));
        btnJoin->setMaximumSize(QSize(400, 50));

        verticalLayout->addWidget(btnJoin);


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
        toolBtnPhoneNumber = new QToolButton(LoginWindow);
        toolBtnPhoneNumber->setObjectName("toolBtnPhoneNumber");
        toolBtnPhoneNumber->setMinimumSize(QSize(60, 80));
        toolBtnPhoneNumber->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolBtnPhoneNumber);

        toolBtnEnpriseWechat = new QToolButton(LoginWindow);
        toolBtnEnpriseWechat->setObjectName("toolBtnEnpriseWechat");
        toolBtnEnpriseWechat->setMinimumSize(QSize(60, 80));
        toolBtnEnpriseWechat->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolBtnEnpriseWechat);

        toolBtnSSO = new QToolButton(LoginWindow);
        toolBtnSSO->setObjectName("toolBtnSSO");
        toolBtnSSO->setMinimumSize(QSize(60, 80));
        toolBtnSSO->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(toolBtnSSO);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        btnSet->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\350\247\206\351\242\221\344\274\232\350\256\256", nullptr));
        btnMin->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        btnClose->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        label_logo->setText(QCoreApplication::translate("LoginWindow", "TextLabel", nullptr));
        btnWechat_login->setText(QCoreApplication::translate("LoginWindow", "PushButton", nullptr));
        btnJoin->setText(QCoreApplication::translate("LoginWindow", "\345\212\240\345\205\245\344\274\232\350\256\256", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\345\205\266\344\273\226\347\231\273\351\231\206\346\226\271\345\274\217", nullptr));
        toolBtnPhoneNumber->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        toolBtnEnpriseWechat->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        toolBtnSSO->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
