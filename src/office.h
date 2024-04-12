#ifndef OFFICE_H
#define OFFICE_H

#include <semaphore>
#include <condition_variable>
#include <mutex>
#include <queue>
#include "ta.h"

class Office
{
private:
    std::counting_semaphore<3> q_semaphore;
    std::queue<int> student_ids;
    std::queue<int> help_times;
    std::mutex queue_mutex;
    std::condition_variable queue_cond;
    TA *ta;

public:
    Office(TA *_ta);
    bool enterOffice(int student_id, int help_time);
    void startHelping();
};

#endif
