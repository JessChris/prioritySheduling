// Implementation of Priority scheduling algorithm
#include <iostream>
#include <algorithm>

using namespace std;

struct process
{
    int pid;// this is the process ID 
    int burstT;// the CPU burst time 
    int priority;// priority of the process 
};

// sort the processes based on priority
bool sortProcesses(process x, process y)
{
    return (x.priority > y.priority);
}

// finding the waiting time for all processes 
void findWaitingTime(process process[],int waitT[])
{
    // wait time of the first process is always 0
    waitT[0] = 0;

    // calculating the waiting time 
    for (int i = 1; i < 4; i++)
    {
        waitT[i] = process[i - 1].burstT + waitT[i - 1];
    }
}

// Function to calculate turn around time 
void findTurnAroundTime(process process[], int waitT[], int turnAroundT[])
{
    // calculating turnaround time by adding the burst time to the wait time 
    for (int i = 0; i < 4; i++)
    {
        turnAroundT[i] = process[i].burstT + waitT[i];
    }
}

//Function to calculate average time 
void findAvgT(process process[])
{
    int waitT[4];
    int turnAroundTime[4];
    int totalWaitT = 0;
    int totalTurnAroundT = 0;

    //waiting time of all processes 
    findWaitingTime(process, waitT);

    // turn around time for all processes 
    findTurnAroundTime(process, waitT, turnAroundTime);

    //showing the processes 
    cout << "\nProcesses  " << " Burst time  "<< " Waiting time  " << " Turn around time"<<endl;

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < 4; i++)
    {
        totalWaitT = totalWaitT + waitT[i];
        totalTurnAroundT = totalTurnAroundT + turnAroundTime[i];
        cout << "   " << process[i].pid << "\t\t"<< process[i].burstT << "\t    " << waitT[i]<< "\t\t  " << turnAroundTime[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)totalWaitT / (float)4;
    cout << "\nAverage turn around time = "<< (float)totalTurnAroundT / (float)4;
}

void priorityScheduling(process proc[])
{
    // Sort processes by priority 
    sort(proc, proc + 4, sortProcesses);

    cout << "Order in which processes gets executed"<<endl;
    for (int i = 0; i < 4; i++)
        cout << proc[i].pid << " ";

    findAvgT(proc);
}

// Driver code 
int main()
{
    process proc[] = { {1, 12, 5}, {2, 6, 2}, {3, 7, 1}, {4,14,5 } };
    priorityScheduling(proc);
    return 0;
}