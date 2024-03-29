#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileInfo info("C:/QtProjects/WidgetsQT/STD-FileManager/FfLW.txt");


    qDebug() << info.fileName();


    if(info.completeSuffix() == "txt")
    {
        qDebug() << info.completeSuffix();
        while(1)
        {
            //checkfile
        }
    }
    return a.exec();
}
