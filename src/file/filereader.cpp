#include"file/file.h"


 FileReader:: FileReader(const QString  path) : path(path)
{
   create_file(path);

}

 FileReader:: FileReader(const File & file)
{
    this->operator =(file);
}

 FileReader &  FileReader:: operator =(const File& file_copy)
{
    this->path = file_copy.path;
    if(file_byte)
    {
        file_byte->close();
        file_byte = NULL;
    }
    if(file_copy.file_byte)
    {
       create_file(this->path);
    }
    return *this;
}

 FileReader:: FileReader(  FileReader && file)
{
    Move(file);
}

 FileReader &  FileReader::operator =( FileReader && file)
{

     Move(file);
     return *this;
}

void  FileReader::Move( FileReader &file)
{
    this->path = std::move( file.path);
    if(file.file_byte)
    {
        this->file_byte =  std::move(file.file_byte);
    }

}


QString      FileReader::getFileInfo()
{
    QFileInfo file_info(this->path);
    QString str ="size:"+QString ::number(file_info.size())+"\n"+"name:"+file_info.fileName();
    return str;
}

QByteArray  FileReader::read(const quint64 read_size)
{
    if(!isOpen())
    {
        return 0;
    }
    return file_byte->read(read_size);
}

QByteArray  FileReader::readall()
{
    if(!isOpen())
    {
        return 0;
    }
    return file_byte->readAll();
}

bool  FileReader::isOpen()
{
    return  file_byte && file_byte->isOpen();
}

FileReader::~FileReader()
{
    if(isOpen())
    {
        file_byte->close();
    }
}

bool  FileReader::create_file(QString path)
{
    file_byte = std::make_shared<QFile>(path);
    return  file_byte->open(QIODevice::ReadOnly);
}


