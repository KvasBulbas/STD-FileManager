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
        this->files.push_back(stats);

        return true;
    }
    return false;
}

bool FileManager::deleteFile(const FileStatistic* file)
{

    return false;
}


void FileManager::checkFiles()
{

    for(auto iter = files.begin(); iter != files.end(); iter++)
    {
//        if(iter->pathCheck())
//        {

//            emit deleted(iter);
//            files.remove(iter);
//            qDebug << "File is deleted";

//        }

        if(iter->isChanged())
        {
           //emit changed(iter);
            emit changed();
           qDebug() << "File is changed";
        }

    }
}


void FileManager::abc()
{
    qDebug() << "asdasdads";
}


