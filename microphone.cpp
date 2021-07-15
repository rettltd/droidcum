#include "microphone.h"

#include <QDebug>

microphone::microphone()
{
    QAudioFormat &format = settings::audioFormat;
    QAudioDeviceInfo &adev = settings::audioDeviceInfo;

    format.setChannelCount(2);
    format.setSampleRate(48000);
    format.setSampleSize(32);
    format.setByteOrder(QAudioFormat::Endian::LittleEndian);
    format.setSampleType(QAudioFormat::SampleType::SignedInt);
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

void microphone::startRecording(NetworkManager *nm)
{
    status = 1;

    //MyBuffer buffer;

    //mbuf.setBuffer(&b);
    mbuf = new MyBuffer(nm);
    mbuf->open(MyBuffer::OpenModeFlag::WriteOnly);

    //audioInput->setBufferSize(8192); //does not help!
    audioInput->start(mbuf);
}
