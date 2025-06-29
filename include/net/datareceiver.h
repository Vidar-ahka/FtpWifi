#ifndef DATARECEIVER_H
#define DATARECEIVER_H
#include"net/idatareceiver.h"
#include"QAbstractSocket"
class DataReceiver : IDataReceiver
{
public:
    DataReceiver() = default;
    DataReceiver(std::shared_ptr<QAbstractSocket> socket);
    virtual ~DataReceiver();
protected:
    virtual  void readyread();

    std::shared_ptr<QAbstractSocket> socket;
};
#endif
