#include"net/datareceiver.h"

DataReceiver::DataReceiver(std::shared_ptr<QAbstractSocket> socket)
{
    this->socket = socket;
    QObject::connect(socket.get(), &QAbstractSocket::readyRead,this, &DataReceiver::readyread);
}

DataReceiver::DataReceiver(DataReceiver && datareceiver)
{
  this->socket =   std::move(datareceiver.socket);


}
DataReceiver & DataReceiver :: operator =(DataReceiver &&datareceiver)
{
    this->socket =   std::move(datareceiver.socket);
    return * this;
}
void DataReceiver::readyread()
{
    emit signalread(this->socket->readAll());
}
