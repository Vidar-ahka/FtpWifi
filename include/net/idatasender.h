#ifndef IDATASENDER_H
#define IDATASENDER_H
#include"QByteArray"
class IDataSender
{
virtual void send(QByteArray) = 0;
virtual ~IDataSernder()= default;
}
#endif

