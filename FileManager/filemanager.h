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

    static FileManager& instanse()
    {
        static FileManager s;

        return s;
    }

    bool addFile(const QString& path);
    bool deleteFile(const FileStatistic file);
    void checkFiles();

    std::list<FileStatistic> files;



signals:
    //void changed(FileStatistic& stats);
    void changed(FileStatistic& stats);
    void deleted(FileStatistic& stats);

public slots:
    void abc(FileStatistic& stats);

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator=(FileManager const&);

};

#endif // FILEMANAGER_H
