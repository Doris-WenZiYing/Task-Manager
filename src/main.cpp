#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Task.h"

void loadTasks(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    std::string desc;
    bool done;
    while (std::getline(file, desc) && file >> done) {
        tasks.emplace_back(desc, done);
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& t : tasks) {
        file << t.getDescription() << "\n" << t.isDone() << "\n";
    }
}

int main() {
    std::vector<Task> tasks;
    const std::string filename = "tasks.txt";
    loadTasks(tasks, filename);

    while (true) {
        std::cout << "\n1. List tasks\n2. Add task\n3. Mark task done\n4. Save & Exit\nChoose: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". [" 
                          << (tasks[i].isDone() ? 'x' : ' ') 
                          << "] " << tasks[i].getDescription() << '\n';
            }
        } else if (choice == 2) {
            std::cout << "Description: ";
            std::string desc;
            std::getline(std::cin, desc);
            tasks.emplace_back(desc);
        } else if (choice == 3) {
            std::cout << "Task number to mark done: ";
            size_t idx;
            std::cin >> idx;
            if (idx > 0 && idx <= tasks.size()) {
                tasks[idx - 1].markDone();
            }
        } else if (choice == 4) {
            saveTasks(tasks, filename);
            break;
        }
    }

    return 0;
}
