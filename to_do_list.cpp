#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Task 
{
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
int main() {
    vector<Task> tasks;
    int choice;
    while (true) 
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
         cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your  choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void addTask(vector<Task>& tasks) 
{
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    Task newTask = { description, false };
    tasks.push_back(newTask);

    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) 
{
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) 
    {
        cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) 
{
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number. Please try again.\n";
        return;
    }

    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask(vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number. Please try again.\n";
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully.\n";
}
