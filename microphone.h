#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QBuffer>

#include "settings.h"

class microphone : public QObject
{
    Q_OBJECT

public:
    microphone();
    ~microphone();

    int status = 0;

public slots:

    void startRecording(QByteArray &b);

private:
    QAudioInput *audioInput = nullptr;
};

#endif // MICROPHONE_H
