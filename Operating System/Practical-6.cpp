#include<iostream>
using namespace std;

struct Process{
    public:
    int pid;
    int arrival_T;
    int burst_Time;    
    int response_Time;
    int waiting_Time;
    int turnaround_Time;
    int complition_Time;
    
};    
    class FCFS
    {
        int n ;
        float   averageturnaroundtime , averagewaitingtime;
        Process *P;
        public:
        void input()
    {
        
        cout<<"Enter the number of process : ";
        cin>>n;
        cout<<"Enter Burst Time for each process : "<<endl;
        P = new Process[n];
        
    
    
        
        
        for(int i=0;i<n;i++)
        {
            cin>>P[i].burst_Time;
        }
        
        cout<<endl;
        
        cout<<"Enter arrival time for "<<n<< " process "<<endl;
        for(int i=0;i<n;i++)
        {
            
             cin>>P[i].arrival_T;
            
        }
        
        cout<<"__________________________________"<<endl;
        cout<<"           GANTT CHART            "<<endl;
        cout<<"__________________________________"<<endl<<endl;
        
        for(int i=1;i<=n;i++)
        {
            cout<<"[P"<<i<<"]      ";
        }
        
        cout<<endl<<"________________________________________________________"<<endl;
        int k=0;
        
        for(int i=0;i<=n;i++)
        {
             
            cout<<k<<"\t ";
            k += P[i].burst_Time;
            
        }
        
    
        
    
        
        for(int i=0;i<n;i++)
        {
            if(i==0){
            
            P[i].complition_Time = P[i].burst_Time;
            
        }
            else
            P[i].complition_Time =  P[i-1].complition_Time + P[i].burst_Time;
            P[i].turnaround_Time = P[i].complition_Time - P[i].arrival_T;
            P[i].waiting_Time = P[i].turnaround_Time - P[i].burst_Time;
        
        }
        
        
        
        P[0].pid;
        int l=100;
        
        for(int i=0;i<n;i++)
        {
            P[i].pid = l;
            l++;
        }
        
        for(int i=0;i<n;i++)
        {
            P[i].response_Time = P[i].waiting_Time;
        }    
            
            
        cout<<endl<<endl;
        
        
        cout<<"_______________________________________________________________________________________________________"<<endl;
        cout<<"Processes  "<<"  PID  "<<" Burst time  " <<" Waiting time  "<<" Turn around time "<<" Response time\n";
        cout<<"_______________________________________________________________________________________________________"<<endl<<endl;
        
        for (int i=0;i<n;i++)
        {
            
        
        averagewaitingtime += P[i].waiting_Time;
        averageturnaroundtime += P[i].turnaround_Time;
        
        cout<<"   "<<i+1;
        cout<<"\t    "<<P[i].pid;
        cout<<"\t\t  "<<P[i].burst_Time;
        cout<<"\t\t  "<<P[i].waiting_Time;
        cout<<"\t\t  "<<P[i].turnaround_Time;
        cout<<"\t\t  "<<P[i].response_Time;
        cout<<endl;
       
        }
        
        cout<<endl<<endl<<"Average Waiting Time : "<<averagewaitingtime/n;
        
        cout<<endl<<"Average TurnAroundTime Time : "<<averageturnaroundtime/n;
    }
    

    
};

    
    

int main()
{
    FCFS obj;
    obj.input();
    return 0;
}
