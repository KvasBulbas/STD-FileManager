#include "filestatistic.h"'


bool FileChecker::isChanged()
{
    QDateTime temp = metadataChangeTime();
    refresh();
    if(isFile() && temp != metadataChangeTime())
        return true;
    return false;
}

