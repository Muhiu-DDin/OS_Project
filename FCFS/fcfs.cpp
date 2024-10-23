// FCFS
#include <iostream>
#include <iomanip>
using namespace std;

struct process{
   int processID;
   int arivalTime;
   int burstTime;
   int completionTime;
   int turnaroundTime;
   int waitingTime;
};

void calculateTurnaroundTime(process processesList[] , int n){
    for(int a = 0 ; a < n ; a++)
    {   
        processesList[a].turnaroundTime = processesList[a].completionTime - processesList[a].arivalTime;
    }
}
void calculateWaitingTime(process processesList[] , int n){
    for(int a = 0 ; a < n ; a++)
    {   
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

void calculation(process processesList[] , int n ){
    int current = 0 ;
    for(int a = 0 ; a < n ; a++){
        if(current < processesList[a].arivalTime){
            current = processesList[a].arivalTime;
        }
        current += processesList[a].burstTime;
        processesList[a].completionTime = current; 
    }
}

int main(){
    int n;
    cout<<"enter no. of processess:";
    cin>> n ;
    process processesList[n];

  for (int a = 0 ; a < n ; a++){
        processesList[a].processID = a+1 ;
     
        cout<<"Enter arival time of process "<< a+1 << "\n" ;
        cin>>processesList[a].arivalTime;

        cout<<"enter burst time of process " << a+1 << "\n" ;
        cin>>processesList[a].burstTime;
    }   

    calculation(processesList , n );
    calculateTurnaroundTime(processesList , n);
    calculateWaitingTime(processesList , n);

    printDetails(processesList , n);

    return 0;
}