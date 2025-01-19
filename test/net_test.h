#include"QTest"
#include"QObject"
#include"QDebug"
#include"QTcpSocket"
#include"file/file.h"
#include"net/connect.h"
#include"thread"
class NetTest : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        std::shared_ptr<File> file = std::make_shared<File>("path");
        Connect con(std::make_unique<QTcpSocket>());
        con.send(file);

    }
private:

};
