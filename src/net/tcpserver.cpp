#include"net/tcpserver.h"

TcpServer::TcpServer(QString addres , quint16 port)
{
    server = std::make_shared<QTcpServer>();
    if(server->listen(QHostAddress(addres),port))
    {

    }
}
