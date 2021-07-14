#include "speaker.h"

speaker::speaker()
{

}

void speaker::start(const QByteArray &b)
{
    speak = new QAudioOutput(settings::audioDeviceInfo, settings::audioFormat, this);

}
