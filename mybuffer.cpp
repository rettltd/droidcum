#include "mybuffer.h"

MyBuffer::MyBuffer(NetworkManager *n, QObject *parent) : QIODevice(parent), netManager(n)
{
    connect(&(n->socket), &QUdpSocket::readyRead, this, &MyBuffer::getFromNet);
}

MyBuffer::~MyBuffer()
{

}

void MyBuffer::getFromNet()
{
    netManager->receiveDatagram(byteData);
    emit QIODevice::readyRead();
}

qint64 MyBuffer::readData(char *data, qint64 maxlen)
{
    char* d = byteData.data();
    qDebug() << byteData.size();
    for(int i=0; i<byteData.size(); i++)
    {
        qDebug() << d[i];
        data[i] = d[i];
    }
    return maxlen;
}

qint64 MyBuffer::writeData(const char *data, qint64 len)
{
    netManager->sendDatagram(QByteArray(data, len));
    return len;
}
