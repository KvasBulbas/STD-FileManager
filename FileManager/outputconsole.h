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
    void deleteFileMessage(FileStatistic& stats);
    void changeFileMessage(FileStatistic& stats);




private:
    ConsoleOfOutput();
    ~ConsoleOfOutput();
    ConsoleOfOutput(ConsoleOfOutput const&);
    ConsoleOfOutput& operator=(ConsoleOfOutput const&);

};

#endif // OUTPUTCONSOLE_H
