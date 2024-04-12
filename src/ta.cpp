#include "ta.h"
#include <iostream>
#include <thread>

void TA::help(int student_id, int help_time)
{
    std::cout << "Helping student " << student_id << " for " << help_time << " seconds." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(help_time));
    std::cout << "Finished helping student " << student_id << "." << std::endl;
}
