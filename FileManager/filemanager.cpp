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

bool FileManager::addFile(const QString& path)
{
    QFileInfo info(path);
    if(info.isFile())
    {
        FileStatistic stats(info);
        files.push_back(stats);
        emit adding(stats);
        return true;
    }

    emit adding_wrongPath(path);
    return false;
}

bool FileManager::deleteFile(const QString& path)
{
    if(files.size() != 0)
        for(auto iter = files.begin(); iter != files.end(); iter++)
            if(iter->getPath() == path)
            {
                emit deleting(*iter);
                files.remove(*iter);
                return true;
            }

    emit deleting_wrongPath(path);
    return false;
}


void FileManager::checkFiles()
{
    for(auto iter = files.begin(); iter != files.end(); iter++)
    {
        if(!iter->pathCheck())
        {
            deleteFile(iter->getPath());
            break;
        }
        else
            if(iter->pathCheck() && iter->isChanged())
                emit changed(*iter);
    }
}



