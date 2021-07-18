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

    /*
    if (netManager->hasPendingDatagrams())
    {


    }
    */
    netManager->receiveDatagram(byteData);
    /// \br
    qDebug() << "MyBuffer::readData() byteData.size() " << byteData.size();
    for(int i=0; i<byteData.size(); ++i)
    {
        if(i > maxlen) break;
            data[i] = byteData.at(i);
    }
    return maxlen;
}

qint64 MyBuffer::writeData(const char *data, qint64 len)
{
    qDebug() << "MyBuffer::writeData() qint64 len: " << len;


    if (inputData.size() < 18000)
        inputData.append(QByteArray(data, len));
    else
    {
        inputData.truncate(16384);
        netManager->sendDatagram(inputData);
        inputData.clear();
    }


/*
    QByteArray written(data, len);
    netManager->sendDatagram(written);
*/

    return len;
}
