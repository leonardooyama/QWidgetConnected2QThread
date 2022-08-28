#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "workerthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_StartThread_clicked();

    void on_pushButton_StartGUIProcess_clicked();

    void handleThreadResults();

    void updateThreadProgress(int value);

private:
    Ui::Widget *ui;
    WorkerThread *thread;
};
#endif // WIDGET_H
