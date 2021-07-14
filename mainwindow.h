#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <microphone.h>

#include <QUdpSocket>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private:
    microphone mic;
};
#endif // MAINWINDOW_H
