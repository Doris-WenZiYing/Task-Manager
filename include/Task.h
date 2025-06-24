#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& desc, bool done=false);
    std::string getDescription() const;
    bool isDone() const;
    void markDone();
private:
    std::string description;
    bool done;
};

#endif // TASK_H
