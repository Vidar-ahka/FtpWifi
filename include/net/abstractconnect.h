#ifndef ABSTRACTCONNECT_H
#define ABSTRACTCONNECT_H
#include"QAbstractSocket"
#include"memory"
#include"file/fileabstract.h"
class AbstractConnect : public QObject
{
    Q_OBJECT
public:
    AbstractConnect() = default;
    AbstractConnect(std::unique_ptr<QAbstractSocket> socket)
    {
        this->socket = std::move(socket);
    }
    virtual QByteArray read() = 0;
    virtual quint64    send(const std::shared_ptr<AbstractFile> file) = 0;
protected:
    std::unique_ptr<QAbstractSocket> socket;
signals:
    void signalread(int id_message,QByteArray byte);

};

#endif
