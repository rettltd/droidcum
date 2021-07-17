#include "microphone.h"

#include <QDebug>

microphone::microphone(NetworkManager *n) : net(n)
{
    QAudioFormat &format = settings::audioFormat;
    QAudioDeviceInfo &adev = settings::audioDeviceInfo;

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

void microphone::startRecording(void)
{
    status = 1;
    //net = new NetworkManager;
    //MyBuffer buffer;

    //mbuf.setBuffer(&b);
    //mbuf = new MyBuffer(nm);
    //mbuf->open(MyBuffer::OpenModeFlag::WriteOnly | MyBuffer::OpenModeFlag::Truncate);

    //audioInput->setBufferSize(8192); //does not help!
    //audioInput->start(mbuf);
    auto io = audioInput->start();
    io->open(QIODevice::ReadOnly);
    connect(io, &QIODevice::readyRead,
        [&, io]() {
            qint64 len = audioInput->bytesReady();
            const int BufferSize = 4192;
            if (len > BufferSize)
                len = BufferSize;

            QByteArray buffer(len, 0);
            qint64 l = io->read(buffer.data(), len);
            if (l > 0)
                net->sendDatagram(QByteArray(buffer.constData(), l));
        });
}
