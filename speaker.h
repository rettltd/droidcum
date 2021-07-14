#ifndef SPEAKER_H
#define SPEAKER_H

#include <QAudioOutput>
#include <QBuffer>

#include "settings.h"

class speaker : public QObject
{
    Q_OBJECT
public:
    speaker();

public slots:
    void start(QByteArray &b);

private:
    QAudioOutput *speak;
};

#endif // SPEAKER_H
