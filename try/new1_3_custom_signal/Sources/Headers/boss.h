//
// Created by YUAN on 2024/4/24.
//

#ifndef NEW1_3_CUSTOM_SIGNAL_BOSS_H
#define NEW1_3_CUSTOM_SIGNAL_BOSS_H

#include <QWidget>
#include <QDebug>


class Boss : public QWidget {
Q_OBJECT

public:
    explicit Boss(QString name, int exp, QWidget *parent = nullptr);

    ~Boss() override;

private:
    int exp;
    QString name;

public slots:
    void BossDead();



signals:
    void BossDeads();
};


#endif //NEW1_3_CUSTOM_SIGNAL_BOSS_H
