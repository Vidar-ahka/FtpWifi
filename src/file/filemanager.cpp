#include"file/filemanager.h"


FileManager::FileManager()
{

}
std::shared_ptr<File> FileManager::getFile(const QString path)
{
    return std::make_shared<File>(path);
}
