#ifndef LOAD_H
#define LOAD_H
#include"QFile"
#include"load.h"
class Load
{
public:
    Load();
    Load(QString path);
    quint64 append(QByteArray & byte);
private:
    std::shared_ptr<QFile> file;
};

#endif
