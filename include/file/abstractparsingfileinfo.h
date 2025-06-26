#ifndef ABSTRACTPARSINGFILEINFO_H
#define ABSTRACTPARSINGFILEINFO_H
#include"QString"
class AbstractParsingFileInfo
{
public:
    AbstractParsingFileInfo()= default;
    AbstractParsingFileInfo(QString fileinfo);
    virtual QString getName()  = 0;
    virtual quint64 getSize()  = 0;
    virtual  ~AbstractParsingFileInfo() = default;
protected:
    QString name;
    quint64 size;
};

#endif
