#ifndef SERVER_H
#define SERVER_H
#include"QTcpServer"
class Server : public QTcpServer
{
    Q_OBJECT
public :
    Server();
private slots:
   void slotread(int id , QByteArray byte);
signals:
   void  signalread(int id , QByteArray byte);
};
#endif
