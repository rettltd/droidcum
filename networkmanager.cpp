#include "networkmanager.h"

NetworkManager::NetworkManager()
{

}

void NetworkManager::sendDatagram(const QByteArray& b)
{
    QHostAddress host;
    host.setAddress(ipaddr);
    QNetworkDatagram packet(b, host, port);

    socket.writeDatagram(packet);
}

void NetworkManager::receiveDatagram(QByteArray &b)
{
    QHostAddress host;
    host.setAddress(ipaddr);
    QNetworkDatagram packet = socket.receiveDatagram();
}
