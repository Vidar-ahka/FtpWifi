#include"net/datasender.h"
DataSender::DataSender(std::shared_ptr<QAbstractSocket> socket)
{
    this->socket = socket;

}


DataSender::DataSender(DataSender && datasender)
{
   this->socket = std::move( datasender.socket);
}
DataSender & DataSender::operator =(DataSender && datasender)
{
    this->socket = std::move( datasender.socket);
    return *this;
}

void DataSender::send(QByteArray byte)
{
    if(socket && !byte.isEmpty() )
    {
        this->send(byte);
    }
}


