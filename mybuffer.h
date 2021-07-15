#ifndef MYBUFFER_H
#define MYBUFFER_H

#include <QIODevice>

#include "networkmanager.h"

class MyBuffer : public QIODevice
{
    Q_OBJECT
public:
    MyBuffer(NetworkManager *n = nullptr, QObject *parent = nullptr);

    virtual ~MyBuffer();

    NetworkManager *netManager;

public slots:
    void getFromNet();

protected:
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

    QByteArray byteData;

};

#endif // MYBUFFER_H
