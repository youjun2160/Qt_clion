//
// Created by YUAN on 2024/4/20.
//

#ifndef TRY_EMIT_SIGNAL_TO_UI_CHILDTHREAD_H
#define TRY_EMIT_SIGNAL_TO_UI_CHILDTHREAD_H

#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class ChildThread; }
QT_END_NAMESPACE

class ChildThread : public QThread {
Q_OBJECT

public:
    explicit ChildThread(QWidget *parent = nullptr);

    ~ChildThread() override;

private:
    Ui::ChildThread *ui;
};


#endif //TRY_EMIT_SIGNAL_TO_UI_CHILDTHREAD_H
