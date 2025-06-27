#include"file/filemetadatacreate.h"



FileMetaDataCreate::FileMetaDataCreate(const QString path,const qint64 chunksize)
{
   setFile(path,chunksize);
}


void  FileMetaDataCreate::  setFile(const QString path, const qint64 chunksize)
{

    QJsonObject  object;

    QFileInfo fileInfo(path);
    qint64 size_file =  fileInfo.size();

    object.insert("name", fileInfo.fileName());
    object.insert("size", size_file);
    object.insert("sizechunk",chunksize);
    QJsonArray array;

    size_t count = 0;

    while(size_file>0)
    {
       size_file =  size_file-chunksize;
       QString future_hash = fileInfo.baseName()+QString::number(size_file) + QString::number(count);
       int hash = qHash(future_hash);
       array.append(hash);
    }
    object.insert("chunks" , array);
    QJsonDocument::setObject(object);
}



