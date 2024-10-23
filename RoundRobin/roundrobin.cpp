// RoundRobin
#include <iostream>
#include <iomanip>
using namespace std;

struct processes{
   int processID;
   int arivalTime;
   int burstTime;
   int completionTime;
   int turnaroundTime;
   int waitingTime;
   int responseTime;
   bool isCompleted;
};

void calculateTurnaroundTime(processes processesList[] , int n){
    for(int a = 0 ; a < n ; a++)
    {   
        processesList[a].turnaroundTime = processesList[a].completionTime - processesList[a].arivalTime;
    }
}

void calculateWaitingTime(processes processesList[] , int n){
    for(int a = 0 ; a < n ; a++)
    {   
        processesList[a].waitingTime = processesList[a].turnaroundTime - processesList[a].burstTime;
    }
}

void calculation(processes processesList[] , int n , int quantum){
    int current = 0 ;
    int completed = 0;

    int remainingTime[n];
    for(int a = 0 ; a < n ; a++)
    {
        remainingTime[a] = processesList[a].burstTime;
    }

    while(completed != n)
    {   

        for(int a = 0 ; a < n ; a++)
        {
           if(remainingTime[a] > 0)
           {

            if(remainingTime[a] > quantum){

                if(processesList[a].responseTime == -1){
                    processesList[a].responseTime = current - processesList[a].arivalTime;
                }

                current = current + quantum;
                remainingTime[a] = remainingTime[a] - quantum;
            }
            else{

                if(processesList[a].responseTime == -1){
                    processesList[a].responseTime = current - processesList[a].arivalTime;
                }

                current = current + remainingTime[a];
                remainingTime[a] = 0;
                processesList[a].completionTime = current;
                processesList[a].isCompleted = true;
                completed++;
            }
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

int main(){
    int n;
    int quantum;
    cout<<"enter no. of processes" << "\n";
    cin>>n;
    cout<<"enter size of quantum" << "\n";
    cin>>quantum;

    processes processesList[n];


    for (int a = 0 ; a < n ; a++){
        processesList[a].processID = a+1 ;
         processesList[a].responseTime = -1;
        processesList[a].isCompleted = false;

        cout<<"Enter arival time of process "<< a+1 << "\n" ;
        cin>>processesList[a].arivalTime;

        cout<<"enter burst time of process " << a+1 << "\n" ;
        cin>>processesList[a].burstTime;
    }   


    calculation(processesList , n , quantum);
    calculateTurnaroundTime(processesList , n);
    calculateWaitingTime(processesList , n);

    printDetails(processesList , n);

    return 0;
}