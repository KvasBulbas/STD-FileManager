#include "filestatistic.h"'
#include <QDebug>

FileStatistic::FileStatistic()
{
    _size = 0;
    _path = "";
    _lastChange = QDateTime();

}

FileStatistic::FileStatistic(QFileInfo& file)
{
    _size = file.size();
    _path = file.absoluteFilePath();
    _lastChange = file.metadataChangeTime();
}

FileStatistic::FileStatistic(const FileStatistic& stats)
{
    _size = stats._size;
    _path = stats._path;
    _lastChange = stats._lastChange;
}

FileStatistic::~FileStatistic()
{

}

QString FileStatistic::getPath()
{
    return _path;
}

int FileStatistic::getSize()
{
    return _size;
}


void FileStatistic::newData(QFileInfo& file)
{
    _size = file.size();
    _lastChange = file.metadataChangeTime();
}


bool FileStatistic::pathCheck()
{
    QFileInfo info(_path);

    return info.isFile();
}

bool FileStatistic::isChanged()
{
    QFileInfo file(_path);
    if(file.isFile() && file.metadataChangeTime() != _lastChange)
    {
        newData(file);
        return true;
    }

    return false;
}

bool FileStatistic::operator ==(const FileStatistic stats)
{
    if(_path == stats._path)
        return true;
    return false;
}

