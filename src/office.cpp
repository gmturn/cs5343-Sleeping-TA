#include "office.h"

Office::Office(TA *_ta) : ta(_ta), q_semaphore(3) {}

bool Office::enterOffice(int student_id, int help_time)
{
    if (!q_semaphore.try_acquire())
    {
        return false;
    }

    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        student_ids.push(student_id);
        help_times.push(help_time);
    }

    queue_cond.notify_one();
    return true;
}

void Office::startHelping()
{
    std::unique_lock<std::mutex> lock(queue_mutex);
    while (true)
    {
        queue_cond.wait(lock, [this]()
                        { return !student_ids.empty(); });

        while (!student_ids.empty())
        {
            int student_id = student_ids.front();
            int help_time = help_times.front();
            student_ids.pop();
            help_times.pop();

            lock.unlock();
            ta->help(student_id, help_time);
            lock.lock();

            q_semaphore.release();
        }
    }
}
