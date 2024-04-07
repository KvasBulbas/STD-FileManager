#include <QCoreApplication>
#include <QDebug>
#include "filemanager.h"
#include "outputconsole.h"
#include <List>
#include <QDir>
#include <QFile>

int main(int argc, char *argv[])
{

    //создание директории с файлами для тестов
    QString dirPath = "C:/QtProjects/WidgetsQT/STD-FileManager/FilesShamonin";
    QDir dir;
    if(dir.mkpath(dirPath))
        qDebug() << "dir is create";


    std::list<QString> fileNames ={"/FfLW1.txt", "/FfLW2.txt", "/FfLW3.txt", "/FfLW4.txt", "/forDelete.txt"};
    for(auto iter = fileNames.begin(); iter != fileNames.end(); iter++)
    {
        QFile file(dirPath + *iter);
        file.open(QIODevice::WriteOnly);
        file.close();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////
    //основная программа
    QCoreApplication a(argc, argv);

    FileManager &manager = FileManager::instanse();
    ConsoleOfOutput &console = ConsoleOfOutput::instanse();

    QObject::connect(&manager, &FileManager::adding, &console, &ConsoleOfOutput::addFile_Message);
    QObject::connect(&manager, &FileManager::deleting, &console, &ConsoleOfOutput::deleteFile_Message);
    QObject::connect(&manager, &FileManager::changed, &console, &ConsoleOfOutput::changeFile_Message);
    QObject::connect(&manager, &FileManager::adding_wrongPath, &console, &ConsoleOfOutput::addFile_wrongPath_Message);
    QObject::connect(&manager, &FileManager::deleting_wrongPath, &console, &ConsoleOfOutput::deleteFile_wrongPath_Message);


    //пытаемся удалить не существущий файл из пустого менеджера
    manager.deleteFile("asdasdasd");

    //пытаемся удалить существущий файл из пустого менеджера
    manager.deleteFile(dirPath + "/forDelete.txt");

    std::list<QString> fileNames2 ={"/Ffasdasdj.txt",//неверное имя файла
                                     "/FfLW1.txt",
                                     "/FfLW2.txt",
                                     "/FfLW3.txt",
                                     "/Fajsdsdj.txt",//неверное имя файла
                                     "/FfLW4.txt",
                                     "/forDelete.txt"};

    //добавление файлов с коректными и не коректоными путями
    for(auto iter = fileNames2.begin(); iter != fileNames2.end(); iter++)
        manager.addFile(dirPath + *iter);

    // пытаемся удалить не существущий файл из не пустого менеджера
    manager.deleteFile("asdasdasd");

   //удаляем существущий файл из менеджера перед тем, как запустить проверку состояний файлов
    manager.deleteFile(dirPath + "/forDelete.txt");
    while(1)
        manager.checkFiles();

    return a.exec();
}
