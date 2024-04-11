#ifndef STUDENT_H
#define STUDENT_H

#include <pthread.h>

class Student
{
private:
    int ID;
    pthread_t threadID;
    int helpTime;

public:
    void program();
    void seekHelp();
    void waitForTA();
    void receiveHelp();
};

#endif // STUDENT_H
