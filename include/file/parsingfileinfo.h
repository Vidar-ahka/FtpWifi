#ifndef PARSINGFILEINFO_H
#define  PARSINGFILEINFO_H
#include"abstractparsingfileinfo.h"
#include"QDebug"
class ParsingFileInfo : public AbstractParsingFileInfo
{
public:

    ParsingFileInfo(QString fileinfo);
    QString getName();
    quint64 getSize();
    virtual ~ParsingFileInfo() = default;
private:
    QString processing(QString lvalue,QString fileinfo);
};
#endif
