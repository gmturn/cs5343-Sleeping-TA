#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "utility/utility.h"
int main()
{
    std::cout << "Hello, World!" << std::endl;

    int randomNum = generateRandomNumber(1, 10);

    std::cout << randomNum << std::endl;
    sleep(randomNum);

    return 0;
}