#ifndef TCPSERVER_H
#define TCPSERVER_H

#include"QTcpServer"
#include"iserver.h"
#include"memory"
class TcpServer :  public IServer , public QTcpServer
{
public:

    TcpServer() = default;
    TcpServer(QString addres , quint16 port);

private:

private slots:
};


#endif
