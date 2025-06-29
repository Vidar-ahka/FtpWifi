#ifndef IDATARECEIVER_H
#define IDATARECEIVER_H
#include"QByteArray"
#include"QObject"
class IDataReceiver : public QObject
{
    Q_OBJECT
public:
    virtual ~IDataReceiver()= default;
signals:
    void signalread(QByteArray byte);
};

#endif
