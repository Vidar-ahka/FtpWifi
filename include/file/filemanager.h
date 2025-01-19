#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include"file.h"
#include"memory"

class FileManager
{
public:
    FileManager();
    std::shared_ptr<File> getFile( const QString path);
private:
};
#endif
