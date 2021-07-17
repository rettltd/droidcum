#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>

#include "mybuffer.h"
#include "settings.h"
#include "networkmanager.h"

class microphone : public QObject
{
    Q_OBJECT

public:
    microphone(NetworkManager *n = nullptr);
    ~microphone();

    int status = 0;

public slots:

    void startRecording(void);

private:
    QAudioInput *audioInput = nullptr;
    MyBuffer *mbuf;
    NetworkManager *net;
};

#endif // MICROPHONE_H
