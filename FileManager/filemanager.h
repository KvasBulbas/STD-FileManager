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
    bool deleteFile(const QString& path);
    void checkFiles();

signals:
    void changed(const FileChecker& checker);
    void deleting(const FileChecker& checker);
    void adding(const FileChecker& checker);
    void adding_wrongPath(const QString path);
    void deleting_wrongPath(const QString path);

private:

    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator=(FileManager const&);
    std::list<FileChecker> files;

};

#endif // FILEMANAGER_H
