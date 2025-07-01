#ifndef TCPSERVER_H
#define TCPSERVER_H

#include"QTcpServer"
#include"iserver.h"
#include"memory"
#include"QTcpSocket"
#include"datareceiver.h"
#include"QHash"
class TcpServer :  public IServer , public QTcpServer
{
public:

    TcpServer() = default;
    TcpServer(QString addres , quint16 port);
    void incomingConnection(qintptr socektDescriptor);





private:
    QHash<qintptr,std::shared_ptr<DataReceiver>> hash_dr;


#endif
