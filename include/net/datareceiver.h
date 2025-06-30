#ifndef DATARECEIVER_H
#define DATARECEIVER_H
#include"net/idatareceiver.h"
#include"QAbstractSocket"
class DataReceiver : public IDataReceiver
{
    Q_OBJECT
public:
    DataReceiver() = default;
    DataReceiver(std::shared_ptr<QAbstractSocket> socket);
    DataReceiver(DataReceiver && datareceiver);
    DataReceiver & operator =(DataReceiver &&datareceiver);

    virtual ~DataReceiver() = default;
protected:
    virtual  void readyread();

    std::shared_ptr<QAbstractSocket> socket;
};
#endif
