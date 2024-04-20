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



    enum State
    {
        Created,
        Changed,
        Deleted
    };

    const State &getState()
    {
        return currentState;
    }

private:

    State currentState = Deleted;


};


#endif // FILESTATISTIC_H
