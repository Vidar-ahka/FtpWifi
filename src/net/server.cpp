#include"net/server.h"


Server:: Server()
{


}
void Server::slotread(int id , QByteArray byte)
{
    emit signalread(id, byte);
}
