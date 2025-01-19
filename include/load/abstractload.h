#ifndef ABSTRACTLOAD_H
#define ABSTRACTLOAD_H
#include"QString"
#include"QByteArray"
class AbstractLoad
{
public:
    AbstractLoad() = default;
    AbstractLoad(QString _path) : path(_path){}
    virtual quint64 append(QByteArray byte) =  0;
    virtual bool isOpen()      = 0;
    virtual bool isCompleted() = 0;
    virtual ~AbstractLoad()
    {

    }
protected:
    QString path;
};
#endif
