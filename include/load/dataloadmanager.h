#ifndef DATALOADMANAGER_H
#define DATALOADMANAGER_H
#include"QString"
#include"QDir"
#include"unordered_map"
#include"load.h"
#include"QStandardPaths"
class  DataLoadManager
{
public:
    DataLoadManager();
    DataLoadManager( const QString _load_dir);
    bool createLoad(const int id,const QString path,const quint64 exsize);
    quint64 appenddata(const int id , const QByteArray byte);
    virtual  ~DataLoadManager() = default;



private:
    bool createloaddir();
    std::unordered_map<int , std::shared_ptr<Load>> load_hash;
    QString load_dir;
};

#endif
