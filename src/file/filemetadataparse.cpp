#include"file/filemetadataparse.h"



void FileMetaDataParse::parse(QByteArray byte)
{
    if(isValid(byte))
    {
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(byte);
    QJsonObject::operator =(doc.object());
}
FileMetaDataParse::FileMetaDataParse(QByteArray byte)
{
    parse(byte);
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

