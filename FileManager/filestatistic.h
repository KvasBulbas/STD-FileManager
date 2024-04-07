#ifndef FILESTATISTIC_H
#define FILESTATISTIC_H
#include <QFileInfo>
#include <QTime>


class FileChecker : public QFileInfo
{
public:
    FileChecker(const QString& path) : QFileInfo(path) {}
    bool isChanged();
};


#endif // FILESTATISTIC_H
