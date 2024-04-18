//
// Created by YUAN on 2024/4/18.
//

#ifndef TRY1_1_SETDIALOG_H
#define TRY1_1_SETDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class SetDialog; }
QT_END_NAMESPACE

class SetDialog : public QDialog {
Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = nullptr);

    ~SetDialog() override;

signals:
    void sig_addOne(int value);

private slots:
    void on_btnAdd_clicked();

private:
    Ui::SetDialog *ui;
};


#endif //TRY1_1_SETDIALOG_H
