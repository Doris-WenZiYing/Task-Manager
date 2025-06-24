#include "Task.h"

Task::Task(const std::string& desc, bool done) 
    : description(desc), done(done) {}

std::string Task::getDescription() const {
    return description;
}

bool Task::isDone() const {
    return done;
}

void Task::markDone() {
    done = true;
}
