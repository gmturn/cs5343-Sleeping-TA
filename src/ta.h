#ifndef TA_H
#define TA_H

#include <queue>

class TA
{
private:
    pthread_t threadID;
    bool isHelping;

public:
    void helpStudent(Student *student);
    void sleep();
    void wakeUp();
    bool isAvailable();
};

#endif // TA_H