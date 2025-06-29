#ifndef IDATASENDER_H
#define IDATASENDER_H
#include"QByteArray"
class IDataSender
{
public:
virtual void send(QByteArray) = 0;
virtual ~IDataSender () = default;
};
#endif

