#ifndef TCPSERVER_H
#define TCPSERVER_H

#include"QTcpServer"
#include"iserver.h"
#include"memory"
#include"QTcpSocket"
#include"datareceiver.h"
#include"QHash"

class TcpServer :  public IServer
{

public:

    TcpServer() = default;
    TcpServer(quint16 port);
    virtual ~TcpServer();

private:
    QHash<qintptr,std::shared_ptr<DataReceiver>> hash_dr;
    std::unique_ptr<QTcpServer> server;

private slots:
    void read(QByteArray byte);
    void disconnect();
    void handleNewConnection();

  };
#endif
