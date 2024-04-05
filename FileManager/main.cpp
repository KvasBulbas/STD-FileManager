#include <QCoreApplication>
#include <QDebug>
#include "filemanager.h"
#include "outputconsole.h"
#include <List>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager &manager = FileManager::instanse();
    ConsoleOfOutput &console = ConsoleOfOutput::instanse();
    QObject::connect(&manager, &FileManager::deleted, &console, &ConsoleOfOutput::deleteFile_Message);
    QObject::connect(&manager, &FileManager::changed, &console, &ConsoleOfOutput::changeFile_Message);
    QObject::connect(&manager, &FileManager::wrongPath, &console, &ConsoleOfOutput::wrongPath_Message);

    std::list<QString> filePaths =
        {"C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff12LW.txt",
         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt",
         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt",
         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW2.txt",
         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW12.txt"};

    for(auto iter = filePaths.begin(); iter != filePaths.end(); iter++)
        manager.addFile(*iter);

    while(1)
        manager.checkFiles();

    return a.exec();
}
