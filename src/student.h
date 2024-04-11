#ifndef STUDENT_H
#define STUDENT_H

#include <pthread.h>
#include <iostream>

class Office;

class Student
{
private:
    int id;
    int helpTime;
    Office *office;
    bool getHelp();
    void program();

public:
    Student(Office *office_);
    void work(int numIterations);
};

#endif // STUDENT_H
