#include "outputconsole.h"
#include <QDebug>

ConsoleOfOutput::ConsoleOfOutput()
{

}

ConsoleOfOutput::~ConsoleOfOutput()
{

}

void ConsoleOfOutput::deleteFile_Message(FileChecker& checker)
{
    qDebug() << "DeleteFie: File" << checker.absoluteFilePath() << "is delete.\n";
}

void ConsoleOfOutput::changeFile_Message(FileChecker& checker)
{
    qDebug() << "File" << checker.absoluteFilePath() << "is changed.";
    qDebug() << "size:" << checker.size() << '\n';
}

void ConsoleOfOutput::addFile_Message(FileChecker& checker)
{
    qDebug() << "AddFile: File" << checker.absoluteFilePath() << "has been added to the manager.";
    qDebug() << "size:" << checker.size() << '\n';
}


void ConsoleOfOutput::addFile_wrongPath_Message(const QString path)
{
    qDebug() << "Addfile: The file" << path << "not added because the path was specified incorrectly\n";
}

void ConsoleOfOutput::deleteFile_wrongPath_Message(const QString path)
{
    qDebug() << "Deletefile: The file" << path << "not deleted because the path was specified incorrectly or manager is empty\n";
}



