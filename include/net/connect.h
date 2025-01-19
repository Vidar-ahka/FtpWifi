#ifndef CONNECT_H
#define CONNECT_H
#include"abstractconnect.h"
#include"QTcpSocket"
class Connect : public AbstractConnect
{
    Q_OBJECT
public:
    Connect() = default;
    Connect(std::unique_ptr<QAbstractSocket> socket);
    QByteArray read() override;
    quint64    send( const std::shared_ptr<AbstractFile> file) override;

private:
   static int id;
    int id_connect;
private slots:
    void readyread();


};
#endif
