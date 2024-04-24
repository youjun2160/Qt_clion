//
// Created by YUAN on 2024/4/24.
//

#ifndef NEW1_3_CUSTOM_SIGNAL_CUSTOMSIGNAL_H
#define NEW1_3_CUSTOM_SIGNAL_CUSTOMSIGNAL_H

#include <QWidget>


class CustomSignal : public QWidget {
Q_OBJECT

public:
    explicit CustomSignal(QWidget *parent = nullptr);

    ~CustomSignal() override;

public slots:
    void BossDeadBC();


};


#endif //NEW1_3_CUSTOM_SIGNAL_CUSTOMSIGNAL_H
