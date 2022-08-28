#include "workerclass.h"

WorkerClass::WorkerClass(QObject *parent)
    : QObject{parent}
{
}

void WorkerClass::ConfigureThread(QThread *thread)
{
    connect(thread, &QThread::started, this, &WorkerClass::DoHardWork);
}

void WorkerClass::DoHardWork()
{
    for (int i = 0; i <= 100; i++)
    {
        Delay(25);
        emit percentDone(i);
    }
    emit workDone();
    emit simpleMessage("Work done!");
    emit windowedMessage(QMessageBox::Information, "Thread status", "Work complete!");
}

void WorkerClass::Delay(unsigned int miliseconds)
{
    QTime dieTime= QTime::currentTime().addMSecs(miliseconds);
    while (QTime::currentTime() < dieTime)
    {
    }
}
