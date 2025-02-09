#include"net/server.h"
#include"QString"

void Server::slotread(int id , QByteArray byte)
{
    emit signalread(id, byte);
}
