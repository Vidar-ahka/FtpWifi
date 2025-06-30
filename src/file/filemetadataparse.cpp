#include"file/filemetadataparse.h"



void FileMetaDataParse::parse(QByteArray byte)
{


}

bool FileMetaDataParse::isValid(QByteArray byte)
{
    if(byte[0] != '{' && byte[0] != '[')
    {
        return false;
    }
    QJsonParseError parse;
    QJsonDocument::fromJson(byte,&parse);
    return parse.error == QJsonParseError::NoError;
}

