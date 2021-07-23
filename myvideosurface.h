#ifndef MYVIDEOSURFACE_H
#define MYVIDEOSURFACE_H

#include <QAbstractVideoSurface>
#include <QCamera>
#include <QBuffer>
#include "networkmanager.h"

class MyVideoSurface : public QAbstractVideoSurface
{
public:
    MyVideoSurface(NetworkManager *nm = nullptr, QObject *parent = nullptr);

    QBuffer *buffer;

protected:
    bool present(const QVideoFrame &frame) override;
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle) const override;

private:
    NetworkManager *netman;
    QCamera *cam;
    QByteArray *frameData;
};

#endif // MYVIDEOSURFACE_H
