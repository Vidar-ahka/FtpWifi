#include"load/load.h"

Load::Load(){}
Load::Load(QString path):AbstractLoad(path)
{
   qDebug()<<"file _ open"<<  create_file(path);

}
quint64  Load::append(QByteArray  byte)
{
    if(isOpen())
    {
        qDebug()<<"QDebug() " << byte.size();
        file->write(byte);
        return byte.size();
    }
    return 0 ;
}

bool Load::create_file(QString path)
{
    file = std::make_shared<QFile>(path);
    return file->open(QIODevice::Append);
}

Load::~Load()
{
    if(isOpen())
    {
       file->close();
    }

}

bool Load::isOpen()
{
    return file&&file->isOpen();
}
