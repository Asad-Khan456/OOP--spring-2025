#include "iostream"
#include "string"

using namespace std;

class Planner 
{
public:
    string tasks[31];  

    Planner() 
    {
        for (int index = 0; index < 31; index++) 
        {
            tasks[index] = "";  
        }
    }

    void addTask(int selectedMonth);
    void removeTask(int selectedMonth);
    void displayTasks(Planner months[]);
};

void Planner::addTask(int selectedMonth)  
{
    int selectedDay = 0;
    
    cout << "Opening task planner for month " << selectedMonth + 1 << endl;

    if (selectedMonth == 3 || selectedMonth == 5 || selectedMonth == 8 || selectedMonth == 10) 
    { 
        while (selectedDay < 1 || selectedDay > 30) 
        {
            cout << "Enter a day to add a task (1-30): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 30) 
            {
                cout << "Invalid date, this month only has 30 days" << endl;
            }
        }
    } 
    else if (selectedMonth == 1) 
    { 
        while (selectedDay < 1 || selectedDay > 28) 
        {
            cout << "Enter a day to add a task (1-28): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 28) 
            {
                cout << "Invalid date, this month only has 28 days" << endl;
            }
        }
    } 
    else 
    { 
        while (selectedDay < 1 || selectedDay > 31) 
        {
            cout << "Enter a day to add a task (1-31): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 31) 
            {
                cout << "Invalid date, this month only has 31 days" << endl;
            }
        }
    }

    if (tasks[selectedDay - 1] != "")  
    {
        cout << "This day already has a task: " << tasks[selectedDay - 1] << endl;
        return;
    }

    cout << "Enter a task for this day: ";
    cin.ignore();  
    getline(cin, tasks[selectedDay - 1]);

    cout << "Task added successfully" << endl;
}

void Planner::removeTask(int selectedMonth)
{
    int selectedDay = 0;
    
    cout << "Opening task remover for month " << selectedMonth + 1 << endl;

    if (selectedMonth == 3 || selectedMonth == 5 || selectedMonth == 8 || selectedMonth == 10) 
    { 
        while (selectedDay < 1 || selectedDay > 30) 
        {
            cout << "Enter a day to remove a task (1-30): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 30) 
            {
                cout << "Invalid date, this month only has 30 days" << endl;
            }
        }
    } 
    else if (selectedMonth == 1) 
    { 
        while (selectedDay < 1 || selectedDay > 28) 
        {
            cout << "Enter a day to remove a task (1-28): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 28) 
            {
                cout << "Invalid date, this month only has 28 days" << endl;
            }
        }
    } 
    else 
    { 
        while (selectedDay < 1 || selectedDay > 31) 
        {
            cout << "Enter a day to remove a task (1-31): ";
            cin >> selectedDay;
            if (selectedDay < 1 || selectedDay > 31) 
            {
                cout << "Invalid date, this month only has 31 days" << endl;
            }
        }
    }

    if (tasks[selectedDay - 1] == "") 
    {
        cout << "No task found for this day" << endl;
        return;
    }

    cout << "Removing task: " << tasks[selectedDay - 1] << endl;
    tasks[selectedDay - 1] = "";  
    cout << "Task removed successfully" << endl;
}

void Planner::displayTasks(Planner months[])  
{
    int foundTasks = 0; 

    for (int currentMonth = 0; currentMonth < 12; currentMonth++)  
    {
        cout << "Month " << currentMonth + 1 << ":" << endl;
        int monthHasTasks = 0;  

        for (int currentDay = 0; currentDay < 31; currentDay++)  
        {
            if (months[currentMonth].tasks[currentDay] != "")  
            {
                cout << "   Day " << currentDay + 1 << ": " << months[currentMonth].tasks[currentDay] << endl;
                monthHasTasks = 1;
                foundTasks = 1;
            }
        }

        if (monthHasTasks == 0)  
        {
            cout << "   No tasks for this month." << endl;
        }
    }

    if (foundTasks == 0)  
    {
        cout << "No tasks found for any month." << endl;
    }
}

int main() 
{
    Planner months[12]; 
    int userChoice = 0;
    
    while (userChoice != 4) 
    {
        cout << "Hello Hassan! What would you like to do?" << endl;
        cout << "1) Add a task for a certain day" << endl;
        cout << "2) Remove a task from a certain day" << endl;
        cout << "3) Display all tasks" << endl;
        cout << "4) Exit the planner" << endl;
        cout << "Enter choice: ";
        cin >> userChoice;

        switch (userChoice) 
        {
            case 1: 
            {
                int selectedMonth = 0;
                while (selectedMonth < 1 || selectedMonth > 12) 
                {
                    cout << "For which month (1-12) would you like to add a task? ";
                    cin >> selectedMonth;
                    if (selectedMonth < 1 || selectedMonth > 12) 
                    {
                        cout << "Invalid month, please choose between 1 and 12" << endl;
                    }
                }
                months[selectedMonth - 1].addTask(selectedMonth - 1);  
                break;
            }
            case 2:
            {
                int selectedMonth = 0;
                while (selectedMonth < 1 || selectedMonth > 12) 
                {
                    cout << "For which month (1-12) would you like to remove a task? ";
                    cin >> selectedMonth;
                    if (selectedMonth < 1 || selectedMonth > 12) 
                    {
                        cout << "Invalid month, please choose between 1 and 12" << endl;
                    }
                }
                months[selectedMonth - 1].removeTask(selectedMonth - 1);
                break;
            }
            case 3:
                months[0].displayTasks(months);  
                break;
            case 4:
                cout << "Exiting planner" << endl;
                break;
            default:
                cout << "Invalid choice, please try again" << endl;
        }
    }

    return 0;
}
