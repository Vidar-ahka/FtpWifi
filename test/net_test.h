#include"QTest"
#include"QObject"
#include"QDebug"
#include"QTcpSocket"
#include"file/filereader.h"

#include"net/server.h"
#include"thread"
#include"file/filemetadatacreate.h"
class NetTest : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {


        FileMetaDataCreate json("C:/test.rar",300000);


        json.toJson();



        std::shared_ptr<FileReader> file = std::make_shared<FileReader>("path");
        std::unique_ptr<QTcpSocket> u_socket = std::make_unique<QTcpSocket>();

        u_socket->connectToHost(QHostAddress("127.0.0.1"),7777);


    }
private:

};
