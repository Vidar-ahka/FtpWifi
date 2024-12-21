#ifndef ABSTRACTLOAD_H
#define ABSTRACTLOAD_H
#include"QString"
#include"QByteArray"
class AbstractLoad
{
public:
    AbstractLoad();
    AbstractLoad(QString _path) : path(_path){}
    virtual quint64 append(QByteArray byte);

    virtual ~AbstractLoad()
    {

    }
private:
    QString path;
};
#endif
