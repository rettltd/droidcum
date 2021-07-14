#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    bar.resize(4096);
    start_button.setParent(this);
    start_button.setGeometry(0,0,120,120);
    start_button.setText("сасать!");

    shit_into_ears_button.setParent(this);
    shit_into_ears_button.setGeometry(120,120,120,120);
    shit_into_ears_button.setText("ебать меня в ухо...");

    connect(&start_button, &QPushButton::pressed, this,  &MainWindow::record);
    connect(&shit_into_ears_button, &QPushButton::pressed, this,  &MainWindow::listen);
}

MainWindow::~MainWindow()
{

}

void MainWindow::record()
{
    mic.status = 1;
    mic.startRecording(bar);
    while (mic.status)
    {
        netman.sendDatagram(bar);
    }
}

void MainWindow::listen()
{
    speak.start(bar);
    while (true)
    {
        while (netman.hasPendingDatagrams())
        {
            netman.receiveDatagram(bar);
        }
    }

}
