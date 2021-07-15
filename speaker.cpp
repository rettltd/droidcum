#include "speaker.h"

speaker::speaker()
{

}

void speaker::start(NetworkManager *nm)
{

    speak = new QAudioOutput(settings::audioFormat, this);

    mbuf = new MyBuffer(nm);
    mbuf->open(QIODevice::OpenModeFlag::ReadOnly);

    speak->start(mbuf);
}
