#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread(QObject *parent = nullptr);
    ~WorkerThread();
    void run() override;

    int getMinProgressValue() const;
    void setMinProgressValue(int newMinProgressValue = 0);

    int getMaxProgressValue() const;
    void setMaxProgressValue(int newMaxProgressValue = 100);

private:
    int minProgressValue;
    int maxProgressValue;
signals:
    void resultReady();
    void currentProgress(int progress);
};

#endif // WORKERTHREAD_H
