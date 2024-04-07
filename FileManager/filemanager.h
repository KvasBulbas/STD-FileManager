#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFileInfo>
#include <vector>
#include <List>
#include "filestatistic.h"
#include "outputconsole.h"

class FileManager : public QObject
{
    Q_OBJECT
public:

    std::list<FileStatistic> files;
    static FileManager& instanse()
    {
        static FileManager s;

        return s;
    }

    bool addFile(const QString& path);
    bool deleteFile(const QString& path);
    void checkFiles();

signals:
    void changed(FileStatistic& stats);
    void deleting(FileStatistic& stats);
    void adding(FileStatistic& stats);
    void adding_wrongPath(const QString path);
    void deleting_wrongPath(const QString path);

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator=(FileManager const&);


};

#endif // FILEMANAGER_H
