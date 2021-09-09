#include "workerthread.h"

WorkerThread::WorkerThread(QObject *parent): QThread(parent)
{
    this->minProgressValue = 0;
    this->maxProgressValue = 100;
}

WorkerThread::~WorkerThread()
{

}

void WorkerThread::run()
{
    for(int i = this->minProgressValue; i < this->maxProgressValue; i++)
    {
        emit currentProgress(i);
        QThread::usleep(100000);
    }
    emit resultReady();
}

int WorkerThread::getMinProgressValue() const
{
    return minProgressValue;
}

void WorkerThread::setMinProgressValue(int newMinProgressValue)
{
    minProgressValue = newMinProgressValue;
}

int WorkerThread::getMaxProgressValue() const
{
    return maxProgressValue;
}

void WorkerThread::setMaxProgressValue(int newMaxProgressValue)
{
    maxProgressValue = newMaxProgressValue;
}
