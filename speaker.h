#ifndef SPEAKER_H
#define SPEAKER_H

#include <QAudioOutput>
#include "settings.h"

class speaker : public QObject
{
public:
    Q_OBJECT
    speaker();

public slots:
    void start(const QByteArray &b);

private:
    QAudioOutput *speak;
};

#endif // SPEAKER_H
