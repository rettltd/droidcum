#include "mybuffer.h"

MyBuffer::MyBuffer(NetworkManager *n, QObject *parent) : QIODevice(parent), netManager(n)
{
    //connect(&(n->socket), &QUdpSocket::readyRead, this, &MyBuffer::getFromNet);
}

MyBuffer::~MyBuffer()
{

}

/*
void MyBuffer::getFromNet()
{
    //netManager->receiveDatagram(byteData);
    //emit QIODevice::readyRead();
}
*/

qint64 MyBuffer::readData(char *data, qint64 maxlen)
{
    qDebug() << "MyBuffer::readData() netManager->hasPendingDatagrams() " << netManager->hasPendingDatagrams();
    ///
    /// \brief d

    byteData.clear();

    while (netManager->hasPendingDatagrams())
    {
        QByteArray t;
        netManager->receiveDatagram(t);
        byteData.append(t);
    }

    /// \d
    /// \br
    char* d = byteData.data();
    qDebug() << "MyBuffer::readData() byteData.size() " << byteData.size();
    for(int i=0; i<byteData.size(); i++)
    {
        //qDebug() << d[i];
        data[i] = d[i];
    }
    return maxlen;
}

qint64 MyBuffer::writeData(const char *data, qint64 len)
{
    qDebug() << "MyBuffer::writeData() qint64 len: " << len;
    netManager->sendDatagram(QByteArray(data, len));
    return len;
}
