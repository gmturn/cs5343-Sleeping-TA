#include <unistd.h>

#include "student.h"
#include "office.h"

#include "../utility/utility.h"

Student::Student(Office *office_) : office(office_) {}

void Student::program()
{
    int sleepTime = generateRandomNumber();
    std::cout << "Student(" << ID << ") programs for\t" << sleepTime << " seconds\n";
    sleep(sleepTime);
}

void Student::seekHelp()
{
    std::cout << "Student (" << ID << ") seeks help\n";
    if (office->seekHelp(this))
    {
        int sleepTime = generateRandomNumber();
        std::cout << "Student (" << ID << ") receives help for\t" << sleepTime << " seconds\n";
        sleep(sleepTime);
    }
    else
    {
        return;
    }
}

void Student::work(int ta_numVisits)
{
    for (int i = 0; i < ta_numVisits; i++)
    {
        seekHelp();
        program();
    }
}
