#ifndef DATASENDER_H
#define DATASENDER_H
#include"memory"
#include"net/idatasender.h"
#include"QAbstractSocket"
class DataSender : public IDataSender
{
public:
   DataSender()  = default;
   DataSender(std::shared_ptr<QAbstractSocket> socket);
   void send(QByteArray byte) override;
private:
   std::shared_ptr<QAbstractSocket> socket;
}

#endif
