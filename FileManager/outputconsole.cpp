#include "outputconsole.h"
#include <QDebug>

ConsoleOfOutput::ConsoleOfOutput()
{

}

ConsoleOfOutput::~ConsoleOfOutput()
{

}

void ConsoleOfOutput::deleteFile_Message(FileStatistic& stats)
{
    qDebug() << "File" << stats.getPath() << "is delete.";
}

void ConsoleOfOutput::changeFile_Message(FileStatistic& stats)
{
    qDebug() << "File" << stats.getPath() << "is changed.";
    qDebug() << "size:" << stats.getSize();
}

void ConsoleOfOutput::wrongPath_Message(const QString path)
{
    qDebug() << "The file" << path << "not added because the path was specified incorrectly";
}

