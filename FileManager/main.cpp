#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileInfo info("C:/QtProjects/WidgetsQT/STD-File/FfLW.txt");


    qDebug() << info.fileName();

    FileManager& manager = FileManager::instanse();

    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt");
    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt");
    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff1.txt");
//    if(info.completeSuffix() == "txt")
//    {
//        qDebug() << info.completeSuffix();
//        while(1)
//        {
//            //checkfile
//        }
//    }
    return a.exec();
}
