#ifndef TA_H
#define TA_H

#include <queue>

class TA
{
private:
    pthread_t threadID;
    bool isHelping;

public:
    void helpStudent();
    void sleep();
    void wakeUp();
};

#endif // TA_H