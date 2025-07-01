#include"net/tcpserver.h"

TcpServer::TcpServer(QString addres , quint16 port)
{

    server = std::make_unique<QTcpServer>();

    if(!server->listen(QHostAddress(addres),port))
    {
        return;
    }
    connect(server.get(),&QTcpServer::newConnection,this,TcpServer::handleNewConnection);
}
TcpServer::~TcpServer()
{
    hash_dr.clear();
}
void TcpServer:: handleNewConnection()
{
    std::shared_ptr<QTcpSocket> socket(server->nextPendingConnection(),[](QTcpSocket * sock)
    {
        sock->deleteLater();
    });
    std::shared_ptr<DataReceiver> datareceiver = std::make_shared<DataReceiver>(socket);
    hash_dr[socket->socketDescriptor()] = datareceiver;
}


void TcpServer::read(QByteArray byte)
{
    emit signalread(byte);
}

void TcpServer::disconnect()
{
    QTcpSocket * socket  =  static_cast<QTcpSocket*>(sender());
    hash_dr.remove(socket->socketDescriptor());
}
