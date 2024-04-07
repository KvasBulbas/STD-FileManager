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
    qDebug() << "DeleteFie: File" << stats.getPath() << "is delete.\n";
}

void ConsoleOfOutput::changeFile_Message(FileStatistic& stats)
{
    qDebug() << "File" << stats.getPath() << "is changed.";
    qDebug() << "size:\n" << stats.getSize() << '\n';
}

void ConsoleOfOutput::addFile_Message(FileStatistic& stats)
{
    qDebug() << "AddFile: File" << stats.getPath() << "has been added to the manager.";
    qDebug() << "size:" << stats.getSize() << '\n';
}


void ConsoleOfOutput::addFile_wrongPath_Message(const QString path)
{
    qDebug() << "Addfile: The file" << path << "not added because the path was specified incorrectly\n";
}

void ConsoleOfOutput::deleteFile_wrongPath_Message(const QString path)
{
    qDebug() << "Deletefile: The file" << path << "not deleted because the path was specified incorrectly or manager is empty\n";
}



