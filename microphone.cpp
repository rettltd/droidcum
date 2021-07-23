#include "microphone.h"

#include <QDebug>
#include <QBuffer>

microphone::microphone()
{
    QAudioFormat &format = settings::audioFormat;
    QAudioDeviceInfo &adev = settings::audioInDeviceInfo;

    format.setChannelCount(2);
    format.setSampleRate(48000);
    format.setSampleSize(16);
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

    QBuffer *inputBuf = new QBuffer();
    inputBuf->open(QBuffer::ReadWrite);

    //audioInput->setBufferSize(8192); //does not help!

    connect(audioInput, &QAudioInput::notify, [inputBuf, nm]{
        inputBuf->seek(0);
        QByteArray ba = inputBuf->readAll();
        nm->sendDatagram(ba);
        inputBuf->reset();
    });
    audioInput->setNotifyInterval(100);
    audioInput->start(inputBuf);
}
