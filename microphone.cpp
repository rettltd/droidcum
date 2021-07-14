#include "microphone.h"

#include <QDebug>

microphone::microphone()
{
    audioFormat.setChannelCount(2);
    audioFormat.setSampleRate(16000);
    audioFormat.setSampleSize(16);
    audioFormat.setByteOrder(QAudioFormat::Endian::LittleEndian);
    audioFormat.setSampleType(QAudioFormat::SampleType::UnSignedInt);
    audioFormat.setCodec("audio/pcm");

    audioDeviceInfo = QAudioDeviceInfo::defaultInputDevice();
    if (!audioDeviceInfo.isFormatSupported(audioFormat))
    {
            qWarning() << "Default format not supported, trying to use the nearest...";
            audioFormat = audioDeviceInfo.nearestFormat(audioFormat);
    }
    audioInput = new QAudioInput(audioDeviceInfo, audioFormat, this);
}

microphone::~microphone()
{
    delete audioInput; audioInput = nullptr;
}
