#ifndef FILEMETADATAPARSE_H
#define FILEMETADATAPARSE_H


#include <QJsonObject>
#include"QJsonDocument"
#include <QString>
#include"QFileInfo"
#include"QJsonArray"



class FileMetaDataParse : public QJsonObject
{
public:
    FileMetaDataParse()=default;
    ~FileMetaDataParse()=default;
    void parse(QByteArray byte);
    static  bool isValid(QByteArray byte);

private:
};


#endif
