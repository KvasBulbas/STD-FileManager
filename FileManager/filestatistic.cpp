#include "filestatistic.h"'
#include <QDebug>

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

FileStatistic::~FileStatistic()
{

}

void FileStatistic::newData(QFileInfo& file)
{
    _lastSize = file.size();
    _lastName = file.fileName();
    _lastChange = file.metadataChangeTime();
}


bool FileStatistic::pathCheck(QFileInfo &file)
{
    if(_path == file.path())
        return true;
    return false;
}

bool FileStatistic::isChanged()
{
    QString absolutePath = _path + '/' + _lastName;
    QFileInfo file(absolutePath);


    if(file.metadataChangeTime() != _lastChange)
    {
        newData(file);
        return true;
    }


    return false;
}

