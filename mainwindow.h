#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "microphone.h"
#include "networkmanager.h"

#include <QUdpSocket>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void record();

private:
    QPushButton start_button;

    QByteArray bar;
    microphone mic;
    NetworkManager netman;
};
#endif // MAINWINDOW_H
