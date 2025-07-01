#include"net/tcpserver.h"

TcpServer::TcpServer(QString addres , quint16 port)
{
    server = std::make_shared<QTcpServer>();
    if(!server->listen(QHostAddress(addres),port))
    {
        return;
    }
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    std::shared_ptr<QTcpSocket> socket = std::make_shared<QTcpSocket>();
    socket->setSocketDescriptor(socketDescriptor);

    std::shared_ptr<DataReceiver> datareceiver = std::make_shared<DataReceiver>(socket);
    hash_dr[socketDescriptor] = datareceiver;



}



