#include "filemanager.h"
#include <QTime>
#include <QString>

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
        this->files.push_back(info);
        return true;
    }

    return false;
}



void FileManager::checkFiles()
{
    for(int i = 0; i < this->files.size(); i++)
    {

    }
}

