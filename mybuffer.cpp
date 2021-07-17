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

    netManager->receiveDatagram(byteData);
    /// \d
    /// \br
    char* d = byteData.data();
    qDebug() << "MyBuffer::readData() byteData.size() " << byteData.size();
    for(int i=0; i<byteData.size(); i++)
    {
        //qDebug() << d[i];
        if(i > maxlen) break;
        data[i] = d[i];
    }
    return maxlen;
}

qint64 MyBuffer::writeData(const char *data, qint64 len)
{
    qDebug() << "MyBuffer::writeData() qint64 len: " << len;
    /*
    while (netManager->hasPendingDatagrams())
    {
        QByteArray t;
        netManager->receiveDatagram(t);
        byteData.append(t);
    }
    ///
    /// \brief len1
    ///
    qint64 len1 = m_audioInput->bytesReady();*/
    //const int BufferSize = 5000;
    //if (len > BufferSize)
    //    len = BufferSize;

//    QByteArray buffer(len, 0);



    if (inputData.size() < 8384)
        inputData.append(QByteArray(data, len));
    else
    {

        netManager->sendDatagram(inputData);
        inputData.clear();
    }
    return len;
}
