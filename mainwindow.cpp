#include "mainwindow.h"

#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //bar.resize(16384);
    start_button.setParent(this);
    start_button.setGeometry(0,0,120,120);
    start_button.setText("record");

    shit_into_ears_button.setParent(this);
    shit_into_ears_button.setGeometry(120,120,120,120);
    shit_into_ears_button.setText("listen");

    label.setParent(this);
    label.setGeometry(120,0,300,120);
    label.setText("NO messages");

    connect(&start_button, &QPushButton::pressed, this,  &MainWindow::record);
    connect(&shit_into_ears_button, &QPushButton::pressed, this,  &MainWindow::listen);

    //connect(&netman.socket, &QUdpSocket::readyRead, this, &MainWindow::listen);
    mic = new microphone(&netman);
    speak = new speaker();
}

MainWindow::~MainWindow()
{

}

void MainWindow::record()
{
    //mic.status = 1;
    mic->startRecording();
    //auto io = mic->start();
    /*
    QThread::usleep(12);
    QString msg = "a secret came";
    QByteArray byteArr = QByteArray::fromStdString("LOL");
    netman.sendDatagram(byteArr);
    */

}

void MainWindow::listen()
{
    speak->start(&netman);
    /*
    QByteArray byteArr;
    netman.receiveDatagram(byteArr);
    QString str = QString::fromStdString(byteArr.toStdString());
    label.setText(str);
    */
}
