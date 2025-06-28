#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include"filereader.h"
#include"memory"

class FileManager
{
public:
    FileManager();

    std::shared_ptr<FileReader> getFile( const QString path);
    virtual ~FileManager() = default;

private:
};
#endif
