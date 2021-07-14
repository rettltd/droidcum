#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    bar.resize(4096);
    start_button.setParent(this);
    start_button.setGeometry(0,0,120,120);
    start_button.setText("сасать!");
    connect(&start_button, &QPushButton::pressed, this,  &MainWindow::record);
}

MainWindow::~MainWindow()
{

}

void MainWindow::record()
{
    mic.status = 1;
    while (mic.status)
    {
        mic.startRecording(bar);
        netman.sendDatagram(bar);
    }
}
