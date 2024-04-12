#include "student.h"
#include "../utility/utility.h"
#include <iostream>
#include <thread>

Student::Student(int _id, int _helpTime, Office *_office, int num_iterations) : id(_id), helpTime(_helpTime), office(_office), numIterations(num_iterations) {}

void Student::seekHelp()
{
    while (!office->enterOffice(id, helpTime))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Student::program()
{
    int help_time = generateRandomNumber();
    std::cout << "Student " << id << " programming for " << help_time << " seconds." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(help_time));
    std::cout << "Finished helping student " << id << "." << std::endl;
}

void Student::work()
{
    for (int i = 0; i < numIterations; i++)
    {
        seekHelp();
        program();
    }
}