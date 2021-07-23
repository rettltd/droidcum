#ifndef SETTINGS_H
#define SETTINGS_H

#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QCameraInfo>
#include <QVideoEncoderSettings>

class settings
{
public:
    settings();
    static QAudioFormat audioFormat;
    static QAudioDeviceInfo audioInDeviceInfo;
    static QAudioDeviceInfo audioOutDeviceInfo;

    static QVideoEncoderSettings videoEncoding;
    static QCameraInfo cameraInfo;

};

#endif // SETTINGS_H
