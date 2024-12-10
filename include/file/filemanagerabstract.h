#ifndef FILEMANAGERABSTRACT_H
#define FILEMANAGERABSTRACT_H

#include"fileabstract.h"
#include"memory"
class FileManagerAbstract : public QObject
{
public:
    FileManagerAbstract();
    virtual std::shared_ptr<FileAbstract> appendFile(int id,QString path) = 0;
    virtual std::shared_ptr<FileAbstract> getFile   (int id)              = 0;
    virtual std::shared_ptr<FileAbstract> getFile   (QString path)        = 0;

private:
};
#endif
