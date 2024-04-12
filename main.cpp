#include <vector>
#include <thread>
#include "src/office.h"
#include "src/student.h"
#include "src/ta.h"

int main()
{
    TA ta;
    Office office(&ta);

    std::vector<std::thread> threads;
    for (int i = 1; i <= 5; ++i)
    {
        threads.emplace_back([&office, i]()
                             {
            Student student(i, 2, &office, 3);
            student.work(); });
    }

    std::thread taThread([&office]()
                         { office.startHelping(); });

    for (auto &t : threads)
    {
        t.join();
    }

    taThread.detach(); // We detach the TA thread or alternatively could have a stopping condition

    return 0;
}
