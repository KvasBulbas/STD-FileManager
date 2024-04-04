#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include "filemanager.h"
#include "outputconsole.h"
#include "filestatistic.h"

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

    QObject::connect(FileManager::instanse(), FileManager::changed, FileManager::instanse(), FileManager::abc);

//    if(manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt") && manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt"))
//        while(1)
//        {
//            manager.checkFiles();
//        }
        return a.exec();
}
