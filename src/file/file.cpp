#include"file/file.h"

File::File() noexcept{

}

File::File(QString  path) : AbstractFile(path)
{
    file = std::make_shared<QFile>(path);
    if(!file->open(QIODevice::ReadOnly))
    {
        throw "file dont open or dont create";
    }
}
QByteArray File::read(quint64 read_size)
{
    return file->read(read_size);
}
QByteArray File::readall()
{
    return file->readAll();
}
File::~File()
{
    file->close();
}


