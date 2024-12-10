#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include"QHash"
#include"file.h"
#include"filemanagerabstract.h"
class FileManager : public FileManagerAbstract
{
public:
    FileManager(QString path);
    std::shared_ptr<FileAbstract> appendFile(int id,QString path) override;
    std::shared_ptr<FileAbstract> getFile   (int id)              override;
private:
    QString path;
    QHash<int , std::shared_ptr<File>> file;
};
#endif
