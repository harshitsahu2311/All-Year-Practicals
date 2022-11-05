#include<iostream>
#include<iomanip>
#include<conio.h>
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
    int remaining_burst_time;
    int starting_time;
    int priority;
    bool done = false;
};

class PPS
{
    int n;
    float avg_tat , avg_wt , total_tat , total_wt;
    int current , timer;
    Process *p;
    int oldpid;
    public:
        PPS();
        
        bool stop();
        void arrival_sort();
        void Process_sorting();
        void Calculation();
        void gantt_chart();
        void output();
        void process_details(bool,int);
};

PPS :: PPS()
{
    oldpid=-1;
    total_tat = 0;
    avg_tat = 0;
    total_wt = 0;
    avg_wt = 0;
}




void PPS :: process_details(bool ispriority , int priority_order)

{
    cout<<endl<<endl<<"Enter the total number of processes : ";
    cin>>n;
    
    p = new Process[n];
    
    cout<<endl<<endl<<"Enter the arrival time of each process : "<<endl;
    for(int i=0; i<n; i++)
    {
        p[i].pid = i;
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].arrival_time;
    }
    
    cout<<endl<<endl<<"Enter the burst time of each process : "<<endl;    
    for(int i=0; i<n; i++)
    {
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].burst_time;
        p[i].remaining_burst_time = p[i].burst_time;
    }
    
    int x;
    if(ispriority)
    {
        cout<<endl<<endl<<"Enter the priority of each process : "<<endl;    
        for(int i=0; i<n; i++)
        {
            cout<<"[P"<<p[i].pid<<"] : ";
            cin>>x;
            p[i].priority = x * priority_order;
        }
    }
    
    Process_sorting();
}

void PPS :: Process_sorting()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(p[j].arrival_time > p[j+1].arrival_time)
            {
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void PPS :: Calculation()
{
    
    
    cout<<"\n Priority Order (1) for Higher-Lower (-1) for Lower-Higher : ";
    int priority_order;
    cin>>priority_order;
    

    process_details(1,priority_order);
    cout<<"\n\nGANTT CHART\n\n";
    current = 0;
    timer = 0+p[current].arrival_time;
    while(!stop())
    {
        if(timer >= p[current].arrival_time)
        {
            for(int i=0;i<n;i++)
            {
                if((p[i].pid!=current)&&(!p[i].done)&&(timer >= p[i].arrival_time))
                {
                    if(p[i].priority > p[current].priority)
                    {
                        current = i;
                    }
                }
            }
            
            if(oldpid!=p[current].pid)
            {
                cout<<"("<<timer<<")--P"<<p[current].pid<<"--";
                oldpid=p[current].pid;
            }
            
            if(!p[current].done)
            {
                if(p[current].remaining_burst_time > 1)
                {
                    p[current].remaining_burst_time--;
                    timer++;
                    
                
                }
                else
                {
                    p[current].remaining_burst_time--;
                    timer++;
                    p[current].completion_time = timer;
                    p[current].done = true;
                    p[current].turnaround_time = p[current].completion_time - p[current].arrival_time;
                    p[current].waiting_time = p[current].turnaround_time - p[current].burst_time;
                    
                }
                
                    if(current==n || timer<p[current+1].arrival_time)
                    {
                        cout<<"("<<current<<")";
                        if(current!=n)
                        cout<<"---";

                        
                        
                        
                    }
            }
            
            else
            {
                for(int i=0;i<n;i++)
                {
                    if((timer >= p[i].arrival_time)&&(!p[i].done))
                    {
                        current = i;
                        break;
                    }
                }
            }
        }
        
        else
        {
            timer++;
        }
    }
    cout<<p[n-1].completion_time;
}

bool PPS :: stop()
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].done)
        {
            c++;
        }
    }
    if(c==n)
    return true;
    return false;
}



void PPS :: output()
{
        
     cout<<endl<<endl;
      cout<<endl<<"Processes | "<<"Arrival time | "<<"Burst time | "<<"Completion time | "<<"Waiting time | "<<"Response time | "<<" Turn around time | "<<" Priority "<<endl;
     
    for (int i=0; i<n; i++)
    {
        p[i].response_time = p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
       cout<<"P"<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].response_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].priority<<endl;
    }
    
    cout<<endl;
    avg_tat = total_tat/n;
    avg_wt = total_wt/n;
    
    

    cout<<"Total Turnaround time ------ "<<total_tat<<endl;
    
    cout<<"Average Turnaround time ------ "<<avg_tat<<endl;
    
    cout<<"Total Waiting time ------ "<<total_wt<<endl;
    cout<<"Average Waiting time ----- "<<avg_wt<<endl;
    
    
}

int main()
{
    PPS ob;
    
    cout<<"\n ~~~~~~~~ Preemptive priority based scheduling algorithm ~~~~~~~~~ \n";

    ob.Calculation();
    ob.output();
    getch();
    return 0;
    
}
