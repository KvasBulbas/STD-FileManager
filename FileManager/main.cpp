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
    QObject::connect(&manager, &FileManager::adding, &console, &ConsoleOfOutput::addFile_Message);
    QObject::connect(&manager, &FileManager::deleting, &console, &ConsoleOfOutput::deleteFile_Message);
    QObject::connect(&manager, &FileManager::changed, &console, &ConsoleOfOutput::changeFile_Message);
    QObject::connect(&manager, &FileManager::adding_wrongPath, &console, &ConsoleOfOutput::addFile_wrongPath_Message);
    QObject::connect(&manager, &FileManager::deleting_wrongPath, &console, &ConsoleOfOutput::deleteFile_wrongPath_Message);

    QFileInfo abc("C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff12LW.txt");
    QFileInfo abc2("C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff12LW.txt");
    if(abc == abc2)
        qDebug() << "asasd";



//    std::list<QString> filePaths =
//        {"C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff12LW.txt",//указан не корректный путь
//         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt",
//         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt",
//         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW2.txt",
//         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW12.txt"};//указан не корректный путь

//    //пытаемся удалить не существущий файл из пустого менеджера
//    manager.deleteFile("asdasdasd");

//    //пытаемся удалить существущий файл из пустого менеджера
//    manager.deleteFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt");

//    //добавление файлов с коректными и не корректными путями
//    for(auto iter = filePaths.begin(); iter != filePaths.end(); iter++)
//        manager.addFile(*iter);

//    // пытаемся удалить не существущий файл из не пустого менеджера
//    manager.deleteFile("asdasdasd");

//    //удаляем существущий файл из менеджера перед тем, как запустить проверку состояний файлов
//    manager.deleteFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt");
//    while(1)
//        manager.checkFiles();

    return a.exec();
}
