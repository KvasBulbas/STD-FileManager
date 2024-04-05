#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include "filemanager.h"
#include "outputconsole.h"
#include "filestatistic.h"
#include "List"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QFileInfo info("C:/QtProjects/WidgetsQT/STD-FileManager/Files/abc.txt");
//    QFileInfo info1("C:/QtProjects/WidgetsQT/STD-FileManager/Files/abc1.txt");



//    qDebug() << info.birthTime().toSecsSinceEpoch();
//    qDebug() << info1.birthTime().toSecsSinceEpoch();
//    if(info.birthTime() == info1.birthTime())
//        qDebug() << "trueabc";
//    else
//        qDebug() << "falseabc";


//    FileManager& manager = FileManager::instanse();
//    ConsoleOfOutput& console = ConsoleOfOutput::instanse();


//    std::list<int> abc;

//    abc.push_back(1);
//    abc.push_back(2);
//    abc.push_back(3);

//    for(auto iter = abc.begin(); iter != abc.end(); iter++)
//    {
//        qDebug() << *iter;
//    }
//    int forDelete = 0;

//    for(auto iter = abc.begin(); iter != abc.end(); iter++)
//    {
//        if(*iter == 1)
//        {
//            abc.remove(*iter);
//            break;
//        }
//    }
//    /*if(forDelete != 0)
//        abc.remove(forDelete);*/

//    for(auto iter = abc.begin(); iter != abc.end(); iter++)
//    {
//        qDebug() << *iter;
//    }




    FileManager &manager = FileManager::instanse();
    ConsoleOfOutput &console = ConsoleOfOutput::instanse();
    QObject::connect(&manager, &FileManager::changed, &console, &ConsoleOfOutput::changeFileMessage);

    std::list<QString> paths =
        {"C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt",
         "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt",
          "C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW2.txt"};



    if( manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt"))
        while(1)
        {
            manager.checkFiles();
        }

//    for(auto iter = manager.files.begin(); iter != manager.files.end(); iter++)
//    {

//            qDebug() << iter->getSize();
//    }

//    FileStatistic forDelete;

//    for(auto iter = manager.files.begin(); iter != manager.files.end(); iter++)
//        {
//        if(iter->getSize() == 174)
//            {
//                forDelete = *iter;
//            }
//        }

//    manager.files.remove(forDelete);
//        qDebug() << manager.files.size();

//    for(auto iter = manager.files.begin(); iter != manager.files.end(); iter++)
//    {

//        qDebug() << iter->getSize();
//    }

    return a.exec();
}
