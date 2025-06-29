#ifndef ILOAD_H
#define ILOAD_H
#include"QString"
#include"QByteArray"
class ILoad
{
public:
    ILoad() = default;
    virtual quint64 append(QByteArray byte) =  0;
    virtual bool isOpen()      = 0;
    virtual bool isCompleted() = 0;
    virtual ~ILoad() = default;
};
#endif
