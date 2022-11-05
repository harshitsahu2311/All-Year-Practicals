#include<iostream>
#include<iomanip>
using namespace std;

struct Process
{
    int pid;
    int burst_time;
    int waiting_time;
    int response_time;
    int turnaround_time;
    int arrival_time;
    int completion_time;
    int starting_time;
    int remaining_burst_time;
};

class SRTF
{
    int n;
    float  total_turnaround_time, total_waiting_time , average_turnaround_time, average_waiting_time;
    Process *p;
    Process *temp;

    public:
        SRTF();
        void input();
        void arrival_sort();
        void calculation();
        void burst_sort(int, int);
        void output();
};

SRTF :: SRTF()
{    
    total_turnaround_time = 0;
    total_waiting_time  = 0;
    average_turnaround_time = 0;
    average_waiting_time = 0;
}

void SRTF :: input()
{    
    cout<<endl<<endl<<"Enter the total number of processes : ";
    cin>>n;
    
    p = new Process[n];

    cout<<endl<<"Enter the arrival time of each process : "<<endl;
    for(int i=0; i<n; i++)
    {
        p[i].pid = i+1;
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].arrival_time;
    }
    
    cout<<endl<<"Enter the burst time of each process : "<<endl;    
    for(int i=0; i<n; i++)
    {
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].burst_time;
        p[i].remaining_burst_time = p[i].burst_time;
    }
    
    arrival_sort();
}

void SRTF :: arrival_sort()
{    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(p[j].arrival_time > p[j+1].arrival_time)
            swap(p[j], p[j+1]);
        }
    }
}

void SRTF :: burst_sort(int x, int y)
{
    for(int i=x; i<y-1; i++)
    {                
        for(int j=y-1 ;j>i; j--)
        {
            if(p[j].burst_time < p[j-1].burst_time)
            {
                swap(p[j], p[j-1]);
            }
        }
    }
}

void SRTF :: calculation()
{
    int current_time = 0, i = 0, old_pid = -1;
        
    cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~ GANTT CHART ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;;
    cout<<endl;
    
    while(i != n)
    {    
        int j = i;
        
        while(j<n)
        {
            if(p[j].arrival_time > current_time)
            {
                break;
            }
            j++;
        }
        burst_sort(i, j);
        
        if(current_time < p[i].arrival_time)
        {
            current_time = p[i].arrival_time;
        }
            
        if(p[i].remaining_burst_time == p[i].burst_time)
        {
            p[i].response_time = current_time - p[i].arrival_time;    
            p[i].starting_time = current_time;
        }
    
        if(old_pid != p[i].pid)
        {
            cout<<"("<<current_time<<")--P"<<p[i].pid<<"--";
            old_pid=p[i].pid;
        }
        
        p[i].remaining_burst_time--;
        current_time++;
        
        if(p[i].remaining_burst_time == 0)
        {
            p[i].completion_time = current_time;
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        
                            
            ++i;
            
            if(i == n || current_time < p[i+1].arrival_time)
            {
                cout<<"("<<current_time<<")";
                if(i!=n)
                cout<<"----";
            }
        }
    }
    
    cout<<endl<<endl;
}

void SRTF :: output()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(p[j].pid > p[j+1].pid)
            swap(p[j], p[j+1]);
        }
    }
    cout<<" Processes  "<< " Arrival time "<<" Burst time "<<" Completion time "<<" Waiting time  " <<" Turnaround time "<<" Response time "<<endl;
     
    for (int i=0; i<n; i++)
    {
        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
        
        average_turnaround_time = (total_turnaround_time)/n;
        average_waiting_time = (total_waiting_time)/n;
        
        cout<<setw(5)<<p[i].pid<<setw(15)<<p[i].arrival_time <<setw(12)<<p[i].burst_time<<setw(15)<<p[i].completion_time<<setw(15)<<p[i].waiting_time<<setw(15)<<p[i].turnaround_time<<setw(18)<<p[i].response_time<<setw(18)<<endl;
    }
    
    cout<<endl;

    cout<<"Total Waiting time ----- "<<total_waiting_time<<endl;
    cout<<"Average Waiting time ----- "<<average_waiting_time<<endl;
    cout<<"Total Turnaround time ----- "<<total_turnaround_time<<endl;
    cout<<"Average Turnaround time ----- "<<average_turnaround_time<<endl;
}

int main()
{
    SRTF ob;
    
    cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~ SHORTEST REMAINING TASK FIRST ~~~~~~~~~~~~~~~~~~~~~~~ \n";
    ob.input();
    ob.calculation();
    ob.output();
}
