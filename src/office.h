#ifndef OFFICE_H
#define OFFICE_H

#include <semaphore>

#include "ta.h"

class Student;

class Office
{
private:
    int numChairs = 3;
    std::queue<Student *> studentQueue;
    std::counting_semaphore<> chairsSemaphore;

public:
    Office();
    bool seekHelp(Student *student);
    void studentLeaves(Student *student);
    void studentPrograms(Student *student);
    void helpStudent();
};

#endif // OFFICE_H