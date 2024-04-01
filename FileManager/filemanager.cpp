#include "filemanager.h"


FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

bool FileManager::addFile(const QString& Path)
{
    QFileInfo info(Path);
    if(info.isFile() && info.completeSuffix() == "txt")
    {
        files.push_back(info);
        return true;
    }

    return false;
}

