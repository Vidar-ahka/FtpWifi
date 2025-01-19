#include"file/file.h"


File::File(const QString  path) : AbstractFile(path)
{
   create_file(path);
}

File::File(const File & file)
{
    this->operator =(file);
}

File & File:: operator =(const File& file_copy)
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

File::File( File && file)
{
    Move(file);
}

File & File::operator =(File&& file)
{

     Move(file);
     return *this;
}

void File::Move(File &file)
{
    this->path = std::move( file.path);
    if(file.file_byte)
    {
        this->file_byte =  std::move(file.file_byte);
    }

}


QString     File::getFileInfo()
{
    QFileInfo file_info(this->path);
    QString str ="size:"+QString ::number(file_info.size())+"\n"+"name:"+file_info.fileName();
    return str;
}

QByteArray File::read(const quint64 read_size)
{
    if(!isOpen())
    {
        return 0;
    }
    return file_byte->read(read_size);
}

QByteArray File::readall()
{
    if(!isOpen())
    {
        return 0;
    }
    return file_byte->readAll();
}

bool File::isOpen()
{
    return  file_byte && file_byte->isOpen();
}

File::~File()
{
    if(isOpen())
    {
        file_byte->close();
    }
}

bool File::create_file(QString path)
{
    file_byte = std::make_shared<QFile>(path);
    return  file_byte->open(QIODevice::ReadOnly);
}


