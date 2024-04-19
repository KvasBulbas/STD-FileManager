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
    FileChecker checker(path);
    if(checker.isFile())
    {
        files.push_back(checker);
        return true;
    }

    emit adding_wrongPath(path);
    return false;
}

bool FileManager::deleteFile(const QString& path)
{
    if(files.size() != 0)
        for(auto iter = files.begin(); iter != files.end(); iter++)
            if(iter->absoluteFilePath() == path)
            {

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
        if(iter->isChanged())
        {
            if(iter->getState() == "Created")
                emit isFound(*iter);

            if(iter->getState() == "Changed")
                emit changed(*iter);

            if(iter->getState() == "Deleted")
                emit notFound(*iter);
        }

    }
}



