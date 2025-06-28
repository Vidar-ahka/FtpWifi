#ifndef ABSTRACTCONNECT_H
#define ABSTRACTCONNECT_H
#include"QAbstractSocket"
#include"memory"
#include"file/ifilereader.h".h"
class AbstractConnect : public QObject
{
    Q_OBJECT
public:
    AbstractConnect() = default;
    AbstractConnect(std::unique_ptr<QAbstractSocket> socket)
    {
        this->socket = std::move(socket);
    }

    virtual quint64    send(const std::shared_ptr<IFileReader> file) = 0;
    virtual ~AbstractConnect() = default;

protected:
    std::unique_ptr<QAbstractSocket> socket;
signals:
    void signalread(QByteArray byte);
};

#endif
