#ifndef LOAD_H
#define LOAD_H
#include"QFile"
#include"Abstractload.h"
#include"QDebug"
class Load : public  AbstractLoad
{
public:
    Load();
    Load(QString path);
    quint64 append(QByteArray  byte);
    virtual ~Load();
    bool isOpen()
    {
       return file->isOpen();
    }
    bool isCreate()
    {
        return file ? true : false;
    }
private:
    bool create_file(QString path);
    std::shared_ptr<QFile> file;
};

#endif
