#include"net/datasender.h"




DataSender::DataSender(std::shared_ptr<QAbstractSocket> socket):socket(socket){}
void DataSender::send(QByteArray byte)
{
    if(socket && !byte.isEmpty() )
    {
        this->send(byte);
    }
}
