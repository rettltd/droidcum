#include "speaker.h"

speaker::speaker()
{
    speak = new QAudioOutput(settings::audioDeviceInfo, settings::audioFormat, this);
}

void speaker::start(const QByteArray &b)
{
    QIODevice *device = new QBuffer();
    device->open(QIODevice::ReadOnly);
    device->write(b);
    speak->start(device);
}

void speaker::stop()
{
    speak->stop();
}
