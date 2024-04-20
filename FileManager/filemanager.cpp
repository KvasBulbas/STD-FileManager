#include "filemanager.h"
#include <QTime>
#include <QString>
#include <QDebug>
#include "filestatistic.h"


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

            switch(iter->getState())
            {
                case FileChecker::Created:
                    emit isFound(*iter);
                    break;
                case FileChecker::Changed:
                    emit changed(*iter);
                    break;
                case FileChecker::Deleted:
                    emit notFound(*iter);
            }
        }




    }
}



