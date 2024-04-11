#include <unistd.h>

#include "student.h"
#include "office.h"

#include "../utility/utility.h"

Student::Student(Office *office_) : office(office_) {}

bool Student::getHelp()
{
    if (office->helpStudent(id))
    {
        std::cout << "Student(" << id << ") received help\n";
        return true;
    }
    else
    {
        std::cout << "Student(" << id << ") was denied help - office full\n";
        return false;
    }
}

void Student::program()
{
    int sleepTime = generateRandomNumber();
    std::cout << "Student(" << id << ") programs for " << sleepTime << " seconds\n";
    sleep(sleepTime);
    return;
}

void Student::work(int numIterations)
{
    for (int i = 0; i < numIterations; i++)
    {
        getHelp();
        program();
    }
}