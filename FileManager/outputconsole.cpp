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
    qDebug() << "File" << stats.getPath() << "is delete.";
    qDebug() << "size:" << stats.getSize();
}


void ConsoleOfOutput::changeFileMessage(FileStatistic& stats)
{
    qDebug() << "File" << stats.getPath() << "is changed.";
    qDebug() << "size:" << stats.getSize();
}

