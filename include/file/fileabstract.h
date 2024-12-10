#ifndef  FILEABSTRACT_H
#define  FILEABSTRACT_H
#include"QString"
#include"QObject"
#include"functional"
class FileAbstract
{

public:
    FileAbstract() = default;
    FileAbstract(QString path)
    {

    }

    virtual QByteArray read(quint64 read_size) = 0;
    virtual QByteArray readall() = 0;
    virtual quint64    append(QByteArray byte) = 0;
    virtual ~FileAbstract()
    {

    }
private:


};
#endif
