#include <random>

int generateRandomNumber(int lower = 1, int upper = 7)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(lower, upper);
    return distribution(generator);
}
