#include"load/load.h"

Load::Load(){}
Load::Load(const QString path , const quint64 _exsize):AbstractLoad(path) , exsize(_exsize) , cursize(0)
{
    create_file(path);
}
quint64  Load::append(const QByteArray  byte)
{
    if(isOpen()&&!isCompleted())
    {
        cursize += byte.size();
        file->write(byte);
        return cursize;
    }
    return 0 ;
}

bool Load::create_file(QString path)
{
    file = std::make_shared<QFile>(path);
    return file->open(QIODevice::Append);
}

Load::Load   (const Load &  load)
{
    this->operator =(load);
}
Load::Load   (Load && load)
{
    Move(load);
}
Load & Load::operator = (const Load & load)
{
   create_file(load.path);
   cursize = load.cursize;
   exsize =  load.exsize;
   return *this;
}
Load & Load::operator = (Load && load)
{
    Move(load);
    return *this;
}
Load::~Load()
{
    if(isOpen())
    {
       file->close();
    }
}
void Load::Move(Load &load)
{
    this->file    =  std::move(load.file   );
    this->path    =  std::move(load.path   );
    this->exsize  =  std::move(load.exsize );
    this->cursize =  std::move(load.cursize);
}

bool Load::isOpen()
{
    return file&&file->isOpen();
}

bool Load::isCompleted()
{
    return cursize >= exsize;
}
