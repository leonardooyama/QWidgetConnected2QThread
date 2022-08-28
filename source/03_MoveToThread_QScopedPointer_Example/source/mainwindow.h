#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProgressBar>
#include <QSharedPointer>
#include <QDebug>
#include "workerclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void fillProgressBar(int percent);
    void handleWorkDone();
    void handleSimpleMessage(QString message);
    void handleWindowedMessage(QMessageBox::Icon icon, QString title, QString message);
    void handlePushButton_StartThread_clicked();
private:
    Ui::MainWindow *ui;
    WorkerClass *worker;
    QThread *mThread;
    QProgressBar * progressBar;
    QSharedPointer<WorkerClass> workerClassPtr;
};
#endif // MAINWINDOW_H
