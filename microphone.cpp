#include "microphone.h"

#include <QDebug>

microphone::microphone()
{
    QAudioFormat &format = settings::audioFormat;
    QAudioDeviceInfo &adev = settings::audioDeviceInfo;

    format.setChannelCount(2);
    format.setSampleRate(16000);
    format.setSampleSize(16);
    format.setByteOrder(QAudioFormat::Endian::LittleEndian);
    format.setSampleType(QAudioFormat::SampleType::UnSignedInt);
    format.setCodec("audio/pcm");

    adev = QAudioDeviceInfo::defaultInputDevice();
    if (!adev.isFormatSupported(format))
    {
            qWarning() << "Default format not supported, trying to use the nearest...";
            format = adev.nearestFormat(format);
    }
    audioInput = new QAudioInput(adev, format, this);
}

microphone::~microphone()
{
    delete audioInput; audioInput = nullptr;
}

void microphone::startRecording(QByteArray &b)
{
    b;
    QBuffer buffer;
    buffer.open(QBuffer::OpenModeFlag::WriteOnly);
    buffer.setBuffer(&b);

    audioInput->start(&buffer);
}
