#ifndef FILEMEADATACREATE_H

#define FILEMEADATACREATE_H


#include <QJsonObject>
#include"QJsonDocument"
#include <QString>
#include"QFileInfo"
#include"QJsonArray"


class FileMetaDataCreate : public QJsonDocument {
public:
    FileMetaDataCreate() = default;
    explicit FileMetaDataCreate(const QString path, const qint64 chunksize);
    void  setFile(const QString path, const qint64 chunksize);

};

#endif
