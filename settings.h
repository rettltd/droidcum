#ifndef SETTINGS_H
#define SETTINGS_H

#include <QAudioFormat>
#include <QAudioDeviceInfo>

class settings
{
public:
    settings();
    static QAudioFormat audioFormat;
    static QAudioDeviceInfo audioDeviceInfo;

};

#endif // SETTINGS_H
