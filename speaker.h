#ifndef SPEAKER_H
#define SPEAKER_H

#include <QBuffer>
#include <QAudioOutput>
#include <QIODevice>
#include <QAudioFormat>
#include "settings.h"

class speaker : public QObject
{
public:
    Q_OBJECT
    speaker();

public slots:
    void start(const QByteArray &b);
    void stop();
private:
    QAudioOutput *speak;
    //QIODevice *device;
};

#endif // SPEAKER_H
