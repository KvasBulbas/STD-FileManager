#ifndef FILESTATISTIC_H
#define FILESTATISTIC_H
#include <QFileInfo>
#include <QTime>


class FileStatistic
{
public:
    FileStatistic();
    FileStatistic(const FileStatistic& stats);
    FileStatistic(const QFileInfo& file);
    ~FileStatistic();

    bool isChanged();
    bool pathCheck();
    QString getPath();
    int getSize();

    bool operator==(const FileStatistic& stats);

private:
    void newData(QFileInfo& file);
    int _size  = 0;
    QString _path = "";
    QDateTime _lastChange = QDateTime();
};

#endif // FILESTATISTIC_H
