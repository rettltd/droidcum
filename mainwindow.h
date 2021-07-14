#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "microphone.h"
#include "speaker.h"
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
    void listen();

private:
    QPushButton start_button;
    QPushButton shit_into_ears_button;

    QByteArray bar;
    microphone mic;
    speaker speak;
    NetworkManager netman;
};
#endif // MAINWINDOW_H
