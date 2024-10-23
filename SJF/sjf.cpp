// SJF
#include <iostream>
#include <iomanip>
using namespace std;

struct process {
    int processID;
    int arivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool isCompleted; 
};

void calculateTurnaroundTime(process processesList[], int n) {
    for (int a = 0; a < n; a++) {
        processesList[a].turnaroundTime = processesList[a].completionTime - processesList[a].arivalTime;
    }
}

void calculateWaitingTime(process processesList[], int n) {
    for (int a = 0; a < n; a++) {
        processesList[a].waitingTime = processesList[a].turnaroundTime - processesList[a].burstTime;
    }
}

void printDetails(process processesList[], int n) {
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

void calculation(process processesList[], int n) {
    int completed = 0, current = 0;

    while (completed != n) {
        int shortestIndex = -1;
        int shortestBurst = INT_MAX;

        for (int a = 0; a < n; a++) {
            // check at curr time which processess are available
            if (!processesList[a].isCompleted && processesList[a].arivalTime <= current) {
                if (processesList[a].burstTime < shortestBurst) {
                    shortestBurst = processesList[a].burstTime;
                    shortestIndex = a;
                }
            }
        }

        if (shortestIndex == -1) {
            current++;
        } else {
            current += processesList[shortestIndex].burstTime;
            processesList[shortestIndex].completionTime = current;
            processesList[shortestIndex].isCompleted = true;
            completed++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    process processesList[n];

    for (int a = 0; a < n; a++) {
        processesList[a].processID = a + 1;
        cout << "Enter arrival time of process " << a + 1 << ": ";
        cin >> processesList[a].arivalTime;
        cout << "Enter burst time of process " << a + 1 << ": ";
        cin >> processesList[a].burstTime;
        processesList[a].isCompleted = false;
    }

    calculation(processesList, n);

    calculateTurnaroundTime(processesList, n);
    calculateWaitingTime(processesList, n);

    printDetails(processesList, n);

    return 0;
}