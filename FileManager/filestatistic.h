#ifndef FILESTATISTIC_H
#define FILESTATISTIC_H
#include <QFileInfo>
#include <QTime>


class FileStatistic
{
public:
    FileStatistic();
    FileStatistic(QFileInfo& file);
    ~FileStatistic();

    bool isChanged();
    bool pathCheck(QFileInfo& file);


private:
    void newData(QFileInfo& file);
    int _lastSize = 0;
    QString _path = "";
    QString _lastName = "";
    QDateTime _lastChange = QDateTime();
};

#endif // FILESTATISTIC_H
