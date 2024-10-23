// SRT
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

struct processes {
    int processID;
    int arivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    int remainingTime;
    bool isCompleted;
};

void calculateTurnaroundTime(processes processesList[], int n) {
    for (int a = 0; a < n; a++) {
        processesList[a].turnaroundTime = processesList[a].completionTime - processesList[a].arivalTime;
    }
}

void calculateWaitingTime(processes processesList[], int n) {
    for (int a = 0; a < n; a++) {
        processesList[a].waitingTime = processesList[a].turnaroundTime - processesList[a].burstTime;
    }
}

void calculation(processes processesList[], int n) {
    int current = 0;
    int completed = 0;
    int shortestRemainingTime, shortestIndex;

    while (completed != n) {
        shortestRemainingTime = INT_MAX;
        shortestIndex = -1;

        for (int a = 0; a < n; a++) {
            if (processesList[a].arivalTime <= current && !processesList[a].isCompleted) {
                if(processesList[a].remainingTime < shortestRemainingTime){
                shortestRemainingTime = processesList[a].remainingTime;
                shortestIndex = a;
                }
            }
        }

        if (shortestIndex == -1) {
            current++; 
        }
        else
        {
            processesList[shortestIndex].remainingTime--;
            current++;
            if (processesList[shortestIndex].responseTime == -1) {
                processesList[shortestIndex].responseTime = current - processesList[shortestIndex].arivalTime - 1;
            }
            if (processesList[shortestIndex].remainingTime == 0) {
                processesList[shortestIndex].isCompleted = true;
                processesList[shortestIndex].completionTime = current;
                completed++;
            }
        }
    }
}
void printDetails(processes processesList[], int n) {
    cout << "SJF Algo Results" << "\n";
    for (int a = 0; a < n; a++) {
        cout << "ID  " << setw(2) << setfill('0') << processesList[a].processID << "   ";
        cout << "Arrival " << setw(2) << setfill('0') << processesList[a].arivalTime << "   ";
        cout << "Burst Time " << setw(2) << setfill('0') << processesList[a].burstTime << "   ";
        cout << "Completion Time " << setw(2) << setfill('0') << processesList[a].completionTime << "   ";
        cout << "Turnaround Time " << setw(2) << setfill('0') << processesList[a].turnaroundTime << "   ";
        cout << "Waiting Time " << setw(2) << setfill('0') << processesList[a].waitingTime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    processes processesList[n];

    for (int a = 0; a < n; a++) {
        processesList[a].processID = a + 1;
        processesList[a].responseTime = -1;
        processesList[a].isCompleted = false;

        cout << "Enter arrival time of process " << a + 1 << ": ";
        cin >> processesList[a].arivalTime;

        cout << "Enter burst time of process " << a + 1 << ": ";
        cin >> processesList[a].burstTime;

        processesList[a].remainingTime = processesList[a].burstTime;
    }

    calculation(processesList, n);
    calculateTurnaroundTime(processesList, n);
    calculateWaitingTime(processesList, n);

    printDetails(processesList, n);

    return 0;
}
