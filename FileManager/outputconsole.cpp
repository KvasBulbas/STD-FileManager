#include "outputconsole.h"
#include <QDebug>

ConsoleOfOutput::ConsoleOfOutput()
{

}

ConsoleOfOutput::~ConsoleOfOutput()
{

}


void ConsoleOfOutput::deleteFileMessage(FileStatistic& stats)
{

}


//void ConsoleOfOutput::changeFileMessage(FileStatistic& stats)
//{
//    qDebug() << "File" << stats.getPath() << "is changed." << "New size:" << stats.getSize();
//}

void ConsoleOfOutput::changeFileMessage()
{
    qDebug() << "asdasdads";
}
