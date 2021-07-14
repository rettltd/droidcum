#include "speaker.h"

speaker::speaker()
{

}

void speaker::start(QByteArray &b)
{
    speak = new QAudioOutput(settings::audioDeviceInfo, settings::audioFormat, this);

    QBuffer buf(&b, this);

    speak->start(&buf);
}
