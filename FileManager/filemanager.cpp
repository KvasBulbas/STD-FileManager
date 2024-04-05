#include "filemanager.h"
#include <QTime>
#include <QString>
#include <QDebug>

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
        FileStatistic stats(info);
        files.push_back(stats);
        return true;
    }

    emit wrongPath(Path);
    return false;
}

bool FileManager::deleteFile(const FileStatistic file)
{
    int tempSize = files.size();
    files.remove(file);

    if(tempSize == files.size())
        return true;
    return false;
}


void FileManager::checkFiles()
{
    for(auto iter = files.begin(); iter != files.end(); iter++)
    {
        if(!iter->pathCheck())
        {
            emit deleted(*iter);
            deleteFile(*iter);
            break;
        }
        else
            if(iter->pathCheck() && iter->isChanged())
                emit changed(*iter);
    }
}



