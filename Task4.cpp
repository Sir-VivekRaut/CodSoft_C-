#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool isCompleted;
};

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    cout << "Enter the task description: ";
    string description;
    cin.ignore(); // Clear input buffer
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number. Please try again.\n";
        return;
    }
    tasks[taskNumber - 1].isCompleted = true;
    cout << "Task marked as completed.\n";
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number. Please try again.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Manager ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
