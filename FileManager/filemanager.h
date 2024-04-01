#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFileInfo>
#include <vector>

class FileManager
{
public:

    static FileManager& instanse()
    {
        static FileManager s;

        return s;
    }

    bool addFile(const QString& path);
    bool isChanged(const QFileInfo& info);
    void checkFiles();


private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator=(FileManager const&);
    std::vector<QFileInfo> files;

};

#endif // FILEMANAGER_H
