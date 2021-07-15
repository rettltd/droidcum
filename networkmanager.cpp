#include "networkmanager.h"

NetworkManager::NetworkManager()
{
    QHostAddress host;
    host.setAddress(ipaddr);
    //socket.bind(host, port);
    socket.bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress);
    socket.joinMulticastGroup(host);
}

void NetworkManager::sendDatagram(const QByteArray& b)
{
    QHostAddress host;
    host.setAddress(ipaddr);
    QNetworkDatagram packet(b, host, port);

    socket.writeDatagram(packet);
}

void NetworkManager::receiveDatagram(QByteArray& b)
{
    QHostAddress host;
    host.setAddress(ipaddr);
    QNetworkDatagram packet = socket.receiveDatagram();

    b = packet.data();
    qDebug() << b.size();
}

bool NetworkManager::hasPendingDatagrams()
{
    return socket.hasPendingDatagrams();
}
