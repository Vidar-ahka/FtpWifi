#include"load/load.h"

Load::Load(){}
Load::Load(QString path):AbstractLoad(path)
{
    create_file(path);

}
quint64  Load::append(QByteArray  byte)
{
    if(isOpen())
    {
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

Load::Load   (Load &  load)
{
    this->operator =(load);
}
Load::Load   (Load && load)
{
    Move(load);

}
Load & Load::operator = (Load & load)
{
   create_file(load.path);
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
    this->file = std::move(load.file);
    this->path = std::move(load.path);
}

bool Load::isOpen()
{
    return file&&file->isOpen();
}
