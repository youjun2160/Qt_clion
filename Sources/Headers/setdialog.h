//
// Created by YUAN on 2024/4/18.
//

#ifndef SAMPLE_1_1_SETDIALOG_H
#define SAMPLE_1_1_SETDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class SetDialog; }
QT_END_NAMESPACE

class SetDialog : public QDialog {
    Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = nullptr);

    ~SetDialog() override;

private:
    Ui::SetDialog *ui;
};


#endif //SAMPLE_1_1_SETDIALOG_H
