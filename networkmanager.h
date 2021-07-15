#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QHostAddress>

class NetworkManager : public QObject
{
    Q_OBJECT
public:

    NetworkManager();

    bool hasPendingDatagrams();
    QUdpSocket socket;

public slots:

    void sendDatagram(const QByteArray &b);
    void receiveDatagram(QByteArray &b);

private:


    QString ipaddr = "239.13.69.228";
    //QString ipaddr = "192.168.0.255";
    quint16 port = 42069;
};

#endif // NETWORKMANAGER_H
