#include "myvideosurface.h"

#include <QThread>

MyVideoSurface::MyVideoSurface(NetworkManager *nm, QObject *parent) : QAbstractVideoSurface(parent), netman(nm)
{
    buffer = new QBuffer(frameData);
    buffer->open(QBuffer::ReadOnly);
}

bool MyVideoSurface::present(const QVideoFrame &frame)
{
    int size;
    int bytesPerLine;
    uchar *videoBufferAddress = frame.buffer()->map(QAbstractVideoBuffer::MapMode::ReadOnly, &size, &bytesPerLine);
    //QByteArray data(reinterpret_cast<const char*>(videoBufferAddress), size);
    frameData->setRawData(reinterpret_cast<const char*>(videoBufferAddress), size);

    qDebug() << frameData->size();
    /*
    int n = 1 + size/16384;
    QByteArray bit;
    for(int i=0; i<n-1; ++i)
    {
        bit = data.mid(i*16384, 16384);
        netman->sendDatagram(bit);
   //     qDebug() << bit.size();
        QThread::usleep(100);
    }
    netman->sendDatagram(data.mid((--n)*16384));
    qDebug() << data.mid(n*16384);
    */

    return true;
}

QList<QVideoFrame::PixelFormat> MyVideoSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const
{
    Q_UNUSED(type)
    QList<QVideoFrame::PixelFormat> list;
    list.append(QVideoFrame::PixelFormat::Format_RGB32);
    return list;
}
