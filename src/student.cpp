#include <iostream>
#include <random>
#include <chrono>

#include "student.h"

void Student::program()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, 3);

    int sleepTime = distr(eng);
    std::cout << "Student (" << ID << ")\t Programs for " << sleepTime << " seconds\n";

    // Randomly sleep for a random period between 1 and 3 seconds
    std::chrono::seconds sleepDuration(sleepTime);
    std::this_thread::sleep_for(sleepDuration);
}