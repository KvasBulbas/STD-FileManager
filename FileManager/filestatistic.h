#ifndef FILESTATISTIC_H
#define FILESTATISTIC_H
#include <QFileInfo>
#include <QTime>
#include <QDebug>
#include <Qstring>


class FileChecker : public QFileInfo
{
public:
    FileChecker(const QString& path) : QFileInfo(path) {}
    bool isChanged();

    const QString &getState()
    {
        return stateNames[currentState];
    }

private:
    enum State
    {

        Created,
        Changed,
        Deleted
    };

    State currentState = Deleted;

    QString stateNames[3] =
    {
        "Created",
        "Changed",
        "Deleted"
    };
};


#endif // FILESTATISTIC_H
