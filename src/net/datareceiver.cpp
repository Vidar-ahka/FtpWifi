#include"net/datareceiver.h"

DataReceiver::DataReceiver(std::shared_ptr<QAbstractSocket> socket)
{
    this->socket = socket;

}
 void DataReceiver::readyread()
{
    emit signalread(this->socket->readAll());
}
