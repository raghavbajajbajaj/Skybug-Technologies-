#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to display the list of tasks
void displayTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[X]" : "[ ]") << " " << tasks[i].description << endl;
    }
}

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully." << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character from previous input
                string taskDescription;
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                cout << "Enter the index of the task to mark as completed: ";
                size_t markIndex;
                cin >> markIndex;
                markTaskCompleted(tasks, markIndex);
                break;
            case 4:
                cout << "Enter the index of the task to remove: ";
                size_t removeIndex;
                cin >> removeIndex;
                removeTask(tasks, removeIndex);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
