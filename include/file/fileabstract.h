#ifndef  FILEABSTRACT_H
#define  FILEABSTRACT_H
#include"QString"
#include"QObject"
#include"functional"
class AbstractFile
{

public:
    AbstractFile() = default;
    AbstractFile(const QString _path):path(_path){}
    virtual QByteArray read( const quint64 read_size) = 0;
    virtual QByteArray readall() = 0;
    virtual QString    getFileInfo()=0;
    virtual bool isOpen() = 0;
    virtual ~AbstractFile() = default;
protected:
    QString path;


};
#endif
