#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progressBar = new QProgressBar;
    progressBar->setMaximum(100);
    progressBar->setMinimum(0);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handlePushButton_StartThread_clicked);
    workerClassPtr.reset(new WorkerClass());
    mThread = new QThread;
    worker = workerClassPtr.data();
    worker->moveToThread(mThread);
    connect(worker, &WorkerClass::percentDone, this, &MainWindow::fillProgressBar);
    connect(worker, &WorkerClass::workDone, this, &MainWindow::handleWorkDone);
    connect(worker, &WorkerClass::simpleMessage, this, &MainWindow::handleSimpleMessage);
    connect(worker, &WorkerClass::windowedMessage, this, &MainWindow::handleWindowedMessage);
    connect(mThread, &QThread::started, worker, &WorkerClass::DoHardWork);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillProgressBar(int percent)
{
    progressBar->setValue(percent);
}

void MainWindow::handleWorkDone()
{
    mThread->exit();
    ui->pushButton->setEnabled(true);
}

void MainWindow::handleSimpleMessage(QString message)
{
    ui->statusbar->removeWidget(progressBar);
    ui->statusbar->showMessage(message, 10000);
}

void MainWindow::handleWindowedMessage(QMessageBox::Icon icon, QString title, QString message)
{
    switch (icon)
    {
    case  QMessageBox::Information:
    {
        QMessageBox::information(this, title, message);
        break;
    }
    case  QMessageBox::Warning:
    {
        QMessageBox::warning(this, title, message);
        break;
    }
    case  QMessageBox::Critical:
    {
        QMessageBox::critical(this, title, message);
        break;
    }
    case  QMessageBox::Question:
    {
        QMessageBox::question(this, title, message);
        break;
    }
    default:
    {
        QMessageBox::information(this, title, message);
    }
    }
}

void MainWindow::handlePushButton_StartThread_clicked()
{
    ui->statusbar->clearMessage();
    ui->statusbar->addWidget(progressBar, 1);
    progressBar->show();
    mThread->start();
    ui->pushButton->setEnabled(false);
}

