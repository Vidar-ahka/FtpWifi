#include"net/connect.h"

Connect::Connect(std::unique_ptr<QAbstractSocket> socket)
    : AbstractConnect(std::move(socket))
{
    if(socket == NULL)
    {
       return;
    }
    id_connect = id++;
    QObject::connect(this->socket.get() , &QAbstractSocket::readyRead , this, &Connect::readyread);

}

quint64    Connect::send(const std::shared_ptr<IFileReader > file)
{
    if(file->isOpen())
    {
        return (socket->write(file->getFileInfo().toUtf8()) + socket->write(file->readall()));
    }

    return 0;
}

void Connect::readyread()
{
    emit signalread(socket->readAll());
}

int Connect::id = 0;
