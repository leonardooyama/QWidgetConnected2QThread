#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBarGUI->setValue(ui->progressBarGUI->minimum());
    ui->progressBarThread->setValue(ui->progressBarThread->minimum());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_StartThread_clicked()
{
    ui->pushButton_StartThread->setDisabled(true);
    thread = new WorkerThread(this);
    thread->setMinProgressValue(ui->progressBarThread->minimum());
    thread->setMaxProgressValue(ui->progressBarThread->maximum());
    connect(thread, &WorkerThread::resultReady, this, &Widget::handleThreadResults);
    connect(thread, &WorkerThread::currentProgress, this, &Widget::updateThreadProgress);
    thread->start();
}

void Widget::handleThreadResults()
{
    ui->pushButton_StartThread->setDisabled(false);
}

void Widget::updateThreadProgress(int value)
{
    ui->progressBarThread->setValue(value + 1);
}

void Widget::on_pushButton_StartGUIProcess_clicked()
{
    ui->pushButton_StartGUIProcess->setDisabled(true);
    int progressBarMin, progressBarMax;
    progressBarMin = ui->progressBarGUI->minimum();
    progressBarMax = ui->progressBarGUI->maximum();
    for(int i = progressBarMin; i < progressBarMax; i++)
    {
        ui->progressBarGUI->setValue(i+1);
        QThread::usleep(100000);
    }
    ui->pushButton_StartGUIProcess->setDisabled(false);
}
