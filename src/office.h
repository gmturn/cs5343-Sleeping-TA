#ifndef OFFICE_H
#define OFFICE_H

#include <semaphore>

#include "ta.h"

class Student;

class Office
{
private:
    std::mutex ta_mutex;
    std::counting_semaphore<> q_semaphore;
    TA *ta;
    int numChairs = 3;

public:
    Office();
    bool helpStudent(int s_id);
    void queueStudent(int s_id);
};

#endif // OFFICE_H