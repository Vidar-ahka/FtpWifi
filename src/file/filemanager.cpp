#include"file/filemanager.h"


FileManager::FileManager()
{

}
std::shared_ptr<FileReader> FileManager::getFile(const QString path)
{
    return std::make_shared<FileReader>(path);
}
