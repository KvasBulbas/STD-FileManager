#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFileInfo>
#include <vector>

class FileManager
{
public:

    bool addFile(const QString& path);
    static FileManager& instanse()
    {
        static FileManager s;

        return s;
    }


private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator=(FileManager const&);
    std::vector<QFileInfo> files;

};

#endif // FILEMANAGER_H
