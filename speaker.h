#ifndef SPEAKER_H
#define SPEAKER_H

#include <QAudioOutput>

#include "mybuffer.h"
#include "settings.h"

class speaker : public QObject
{
    Q_OBJECT
public:
    speaker();

public slots:
    void start(NetworkManager *nm);

private:
    QAudioOutput *speak;
    MyBuffer *mbuf;
};

#endif // SPEAKER_H
