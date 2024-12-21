#ifndef  FILEABSTRACT_H
#define  FILEABSTRACT_H
#include"QString"
#include"QObject"
#include"functional"
class AbstractFile
{

public:
    AbstractFile() = default;
    AbstractFile(QString _path):path(_path){}
    virtual QByteArray read(quint64 read_size) = 0;
    virtual QByteArray readall() = 0;
    virtual ~AbstractFile()
    {

    }
protected:
    QString path;


};
#endif
