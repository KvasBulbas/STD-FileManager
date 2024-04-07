#ifndef OUTPUTCONSOLE_H
#define OUTPUTCONSOLE_H
#include "filestatistic.h"

class ConsoleOfOutput: public QObject
{
    Q_OBJECT


public:


    static ConsoleOfOutput& instanse()
    {
        static ConsoleOfOutput s;

        return s;
    }

public slots:
    void deleteFile_Message(FileChecker& checker);
    void changeFile_Message(FileChecker& checker);
    void addFile_Message(FileChecker& checker);
    void addFile_wrongPath_Message(const QString path);
    void deleteFile_wrongPath_Message(const QString path);
private:
    ConsoleOfOutput();
    ~ConsoleOfOutput();
    ConsoleOfOutput(ConsoleOfOutput const&);
    ConsoleOfOutput& operator=(ConsoleOfOutput const&);

};

#endif // OUTPUTCONSOLE_H
