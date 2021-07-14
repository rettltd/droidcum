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
    qDebug() << "codec: " << format.codec() << "\nsample rate: " << format.sampleRate() << "\nbits: " << format.sampleSize() << "\nstereo: " << format.channelCount() << "\nbyteOrder" << format.byteOrder() << "\nsample type: " << format.sampleType();
    audioInput = new QAudioInput(adev, format, this);
}

microphone::~microphone()
{
    delete audioInput; audioInput = nullptr;
}

void microphone::startRecording(QByteArray &b)
{
    status = 1;

    QBuffer buffer;

    buffer.setBuffer(&b);
    buffer.open(QBuffer::OpenModeFlag::WriteOnly);

    audioInput->start(&buffer);
}
