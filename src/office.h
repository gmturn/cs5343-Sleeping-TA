#ifndef OFFICE_H
#define OFFICE_H

#include <semaphore>

#include "student.h"
#include "ta.h"

class Office
{
private:
    int numChairs;
    std::queue<Student *> studentQueue;
    std::counting_semaphore<> chairsSemaphore;

public:
    bool seekHelp(Student *student);
    void studentLeaves(Student *student);
    void studentPrograms(Student *student);
    void helpStudent();
};

#endif // OFFICE_H