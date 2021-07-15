#include "speaker.h"

#include <QDebug>

speaker::speaker()
{

}

void speaker::start(NetworkManager *nm)
{

    QAudioDeviceInfo dev_out_info = QAudioDeviceInfo::defaultOutputDevice();
    speak = new QAudioOutput(dev_out_info, settings::audioFormat, this);

    qDebug() << "output device name: " << dev_out_info.deviceName();

    mbuf = new MyBuffer(nm);
    mbuf->open(QIODevice::OpenModeFlag::ReadOnly);

    speak->start(mbuf);
}
