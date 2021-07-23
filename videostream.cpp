#include "videostream.h"

VideoStream::VideoStream(NetworkManager* nm) : netman(nm)
{

}

qint64 VideoStream::readData(char *data, qint64 maxlen)
{
    while(netman->hasPendingDatagrams())
    {
        QByteArray bit;
        netman->receiveDatagram(bit);
        qDebug() << bit.size();
        frame.append(bit);
    }
}

qint64 VideoStream::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data)
    return len;
}
