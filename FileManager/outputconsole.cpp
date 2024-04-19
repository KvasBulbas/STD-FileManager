#include "outputconsole.h"
#include <QDebug>

ConsoleOfOutput::ConsoleOfOutput()
{

}

ConsoleOfOutput::~ConsoleOfOutput()
{

}

void ConsoleOfOutput::notFound_Message(const FileChecker& checker)
{
    qDebug() << "Delete: File" << checker.absoluteFilePath() << "not exist.\n";
}

void ConsoleOfOutput::changeFile_Message(const FileChecker& checker)
{
    qDebug() << "File" << checker.absoluteFilePath() << "is changed.";
    qDebug() << "size:" << checker.size() << '\n';
}

void ConsoleOfOutput::addFile_Message(const FileChecker& checker)
{
    qDebug() << "Create: File" << checker.absoluteFilePath() << "has been added to the manager.";
    qDebug() << "size:" << checker.size() << '\n';
}


void ConsoleOfOutput::addFile_wrongPath_Message(const QString path)
{
    qDebug() << "AddFile: The file" << path << "not added because the path was specified incorrectly\n";
}

void ConsoleOfOutput::deleteFile_wrongPath_Message(const QString path)
{
    qDebug() << "DeleteFile: The file" << path << "not deleted because the path was specified incorrectly or manager is empty\n";
}



