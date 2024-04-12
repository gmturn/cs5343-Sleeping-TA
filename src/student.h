#ifndef STUDENT_H
#define STUDENT_H

#include "office.h"

class Student
{
public:
    int id;
    int helpTime;
    Office *office;
    int numIterations;

    Student(int _id, int _helpTime, Office *_office, int num_iterations);
    void seekHelp();
    void program();
    void work();
};

#endif
