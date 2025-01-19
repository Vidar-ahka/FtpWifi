#include"net/connect.h"

Connect::Connect(std::unique_ptr<QAbstractSocket> socket)  : AbstractConnect(std::move(socket))
{
    id_connect = id++;
    QObject::connect(this->socket.get() , &QAbstractSocket::readyRead , this, &Connect::readyread);

}
QByteArray Connect::read()
{

}
quint64    Connect::send(const std::shared_ptr<AbstractFile> file)
{
    if(file->isOpen())
    {

        return (socket->write(file->getFileInfo().toUtf8()) + socket->write(file->readall()));
    }
    return 0;
}

void Connect::readyread()
{
    emit signalread(id_connect,socket->readAll());
}

int Connect::id = 0;
