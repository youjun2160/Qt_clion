//
// Created by YUAN on 2024/4/20.
//

#ifndef CH2_1_TENCENTMEETTINGLOGIN_LOGINWINDOW_H
#define CH2_1_TENCENTMEETTINGLOGIN_LOGINWINDOW_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QDialog {
Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

    ~LoginWindow() override;

private:
    Ui::LoginWindow *ui;
};


#endif //CH2_1_TENCENTMEETTINGLOGIN_LOGINWINDOW_H
