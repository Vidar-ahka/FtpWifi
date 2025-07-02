#include"QTest"
#include"QObject"
#include"QDebug"
#include"net/tcpserver.h"
#include"thread"
#include"net/datasender.h"
#include"QTcpSocket"
class NetTest : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        server =  new TcpServer(1111);
        connect(server,&TcpServer::signalread,this,&NetTest::slotread);
        std::shared_ptr<QTcpSocket> socket = std::make_shared<QTcpSocket>();
        socket->connectToHost("127.0.0.1",1111);
        send    = new  DataSender(socket);


    }
    void sendTest()
    {
        byte_send = "tamerlan";
        send->send(byte_send);
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
   void sendMetaDataTest()
    {
        qint64 chunksize = 50000;
        FileMetaDataCreate meta("C:/test.rar",chunksize);
        send->send(meta.toJson());
        std::this_thread::sleep_for(std::chrono::seconds(1));

   }
    void cleanupTestCase()
    {
        delete server;
        delete send;

    }

private slots:
    void slotread(QByteArray byte)
    {
        qDebug()<<byte;
    }

private:
    TcpServer  * server;
    DataSender * send;
    QByteArray   byte_send;
    bool  work;

};
