#include"file/parsingfileinfo.h"


ParsingFileInfo::ParsingFileInfo(QString fileinfo)
{

   this->name = processing("name",fileinfo);
   this->size = processing("size",fileinfo).toUInt();



}
QString  ParsingFileInfo::getName()
{
    return name;
}
quint64  ParsingFileInfo::getSize()
{
    return size;
}

QString ParsingFileInfo::processing(QString lvalue, QString fileinfo)
{
    int name_pos =  fileinfo.indexOf(lvalue);
    if(name_pos==-1)
    {
        return "";
    }
    int colon_pos = fileinfo.indexOf(":", name_pos+lvalue.size());
    if(colon_pos==-1)
    {
       return "";
    }
    name_pos = fileinfo.indexOf('\n',colon_pos);
    ++colon_pos;
    return fileinfo.mid(colon_pos,name_pos-colon_pos);
}

