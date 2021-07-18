#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>

#include "mybuffer.h"
#include "settings.h"

class microphone : public QObject
{
    Q_OBJECT

public:
    microphone();
    ~microphone();

    int status = 0;

public slots:

    void startRecording(NetworkManager* nm);

private:
    QAudioInput *audioInput = nullptr;
    MyBuffer *mbuf;
};

#endif // MICROPHONE_H
