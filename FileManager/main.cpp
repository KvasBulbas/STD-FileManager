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
    QFileInfo info("C:/QtProjects/WidgetsQT/STD-File/Files/FfLW.txt");

    qDebug() << info.fileName();
    qDebug() << info.path();
    FileManager& manager = FileManager::instanse();

    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW.txt");
    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/FfLW1.txt");
    qDebug() << manager.addFile("C:/QtProjects/WidgetsQT/STD-FileManager/Files/Ff1.txt");

    while(1)
    {
        //check
    }
    return a.exec();
}
