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



void FileManager::checkFiles()
{

    for(int i = 0; i < this->files.size(); i++)
    {
        if((this->files[i]).isChanged())
            qDebug() << "File is changed";
    }
}

