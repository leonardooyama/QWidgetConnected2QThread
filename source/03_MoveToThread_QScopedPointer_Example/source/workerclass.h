#ifndef WORKERCLASS_H
#define WORKERCLASS_H

#include <QObject>
#include <QThread>
#include <QTime>
#include <QMessageBox>


class WorkerClass : public QObject
{
    Q_OBJECT
public:
    explicit WorkerClass(QObject *parent = nullptr);
private:
    void Delay(unsigned int miliseconds);
    QThread *workerThread;
public slots:
    void DoHardWork();
signals:
    void percentDone(int percent);
    void workDone();
    void simpleMessage(QString message);
    void windowedMessage(QMessageBox::Icon icon, QString title, QString message);

};

#endif // WORKERCLASS_H
