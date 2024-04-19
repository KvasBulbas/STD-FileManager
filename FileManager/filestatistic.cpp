#include "filestatistic.h"


bool FileChecker::isChanged()
{
    QDateTime temp;

    switch(currentState)
    {
    case Created:
    case Changed:
        temp = metadataChangeTime();
        refresh();
        if(isFile())
        {
            if(temp != metadataChangeTime())
            {
                currentState = Changed;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            currentState = Deleted;
            return true;
        }
    case Deleted:
        refresh();
        if(isFile())
        {
            currentState = Created;
            return true;
        }

    }

    return false;
}


