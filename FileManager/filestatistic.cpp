#include "filestatistic.h"'

FileStatistic::FileStatistic()
{
    _lastSize = 0;
    _path = "";
    _lastName = "";
    _lastChange = QDateTime();


}

FileStatistic::FileStatistic(QFileInfo& file)
{
    _lastSize = file.size();
    _path = file.path();
    _lastName = file.fileName();
    _lastChange = file.metadataChangeTime();
}

void FileStatistic::newData(QFileInfo& file)
{
    _lastSize = file.size();
    _path = file.path();
    _lastName = file.fileName();
    _lastChange = file.metadataChangeTime();
}


bool FileStatistic::pathCheck(QFileInfo &file)
{
    if(_path == file.path())
        return true;
    return false;
}

bool FileStatistic::isChanged(QFileInfo& file)
{
    bool k = false;
    if(file.fileName() != _lastName)
    {
        //class console "name is changed"
        k = true;
    }

    if(file.size() != _lastSize)
    {
        //
        k = true;
    }

    if(file.metadataChangeTime() != _lastChange)
    {
        //
        k = true;
    }

    if(k)
    {
        newData(file);
        return true;
    }
    return false;
}

