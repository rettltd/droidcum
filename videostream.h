#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H

#include <QIODevice>
#include "networkmanager.h"

class VideoStream : public QIODevice
{
public:
    VideoStream(NetworkManager *nm);

    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

    NetworkManager *netman;
    QByteArray frame;
};

#endif // VIDEOSTREAM_H
