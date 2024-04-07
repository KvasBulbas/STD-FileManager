#include "filestatistic.h"'


bool FileChecker::isChanged()
{
    if(isFile())
    {
        QDateTime temp = metadataChangeTime();
        refresh();
        if(temp != metadataChangeTime())
            return true;
    }
    return false;
}

