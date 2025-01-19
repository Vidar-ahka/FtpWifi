#include"load/dataloadmanager.h"

DataLoadManager::DataLoadManager() : load_dir(QStandardPaths::writableLocation(QStandardPaths::DownloadLocation)+"/ftpwifi/")
{

}
DataLoadManager::DataLoadManager(const QString _load_dir) :load_dir(_load_dir)
{
}
bool DataLoadManager::createLoad(const int id, const  QString path, const quint64 exsize)
{
    createloaddir();
    load_hash.emplace(id,std::make_shared<Load>(load_dir+path,exsize));
}
quint64 DataLoadManager::appenddata(const int id, const QByteArray byte)
{
    if(!load_hash.count(id))
    {
        return 0;
    }
    std::shared_ptr<Load> load = load_hash[id];
    quint64 size = load->append(byte);
    if(load->isCompleted())
    {
        load_hash.erase(id);
    }
    return size;
}
bool DataLoadManager::createloaddir()
{
    QDir dir;
    if(!dir.exists(load_dir))
    {
        dir.mkdir(load_dir);
    }
    return dir.exists();
}
