#ifndef IDATARECEIVER_H
#define IDATARECEIVER_H
#include"QByteArray"
class IDataReceiver
{
public:
    virtual IDataReceiver()= default;
signals:
    void signalread(QByteArray byte);

}

#endif
