#ifndef STUDENT_H
#define STUDENT_H

#include <pthread.h>
#include <iostream>

class Office;

class Student
{
private:
    int ID;
    pthread_t threadID;
    int helpTime;
    Office *office;

public:
    Student(Office *office_);
    void program();
    void seekHelp();
    void work(int ta_numVisits);
};

#endif // STUDENT_H
