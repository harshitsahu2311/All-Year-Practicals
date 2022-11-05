#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int complition_time;
    int response_time;
    int waiting_time;
    int turnAround_time;
    int starting_time;
};
class RR
{
private:
    Process *p;
    int *remaining_time;
    int num,quantum,t;
    float wt,tt;
public:
    RR();
    void input();
    void calculate();
    void display();
   
};

RR::RR()
{
    cout<<"Enter the number of process : ";
    cin>>num;
    cout<<"Enter the time Quantum value : ";
    cin>>quantum;
    p = new Process[num];
    remaining_time = new int[num];
}
void RR::input()
{
    cout<<endl<<"Enter the respective process ids "<<endl;
     for(int i=0;i<num;i++)
     {
         cout<<"P"<<" : ";
         cin>>p[i].pid;
     }
    cout<<"Enter the Burst time for processes : "<<endl;
    for(int i=0;i<num;i++)
    {
        p[i].arrival_time=0;
        cout<<"P"<<p[i].pid<<" : ";
        cin>>p[i].burst_time;
          remaining_time[i] = p[i].burst_time;
    }
}
void RR::calculate()
{   
    int c=0;
    t=0;
        cout<<setw(40)<<"---------------GANTT CHART---------------"<<endl<<endl<<endl;
        cout<<p[0].arrival_time;
    while(c!=num)
    {
        
        for(int i = 0 ;i <num;i++)
        {
            if(i==0)
                p[i].starting_time=p[i].arrival_time;
            else
                p[i].starting_time= max(p[i].arrival_time,p[i-1].complition_time);
            if(remaining_time[i] > 0 )
            {
                if(remaining_time[i] > quantum)
                {
                    
                    t = t + quantum;
                    remaining_time[i] = remaining_time[i] - quantum;
                    cout<<"|---P"<<p[i].pid<<"---|";
                    p[i].complition_time=t;
                    cout<<t;
                   
                }
                else
                {
                    t = t + remaining_time[i];
                    p[i].complition_time=t;
                    p[i].turnAround_time=p[i].complition_time-p[i].arrival_time;
                    p[i].waiting_time = p[i].turnAround_time - p[i].burst_time;
                    p[i].response_time=p[i].starting_time-p[i].arrival_time;
                    remaining_time[i] = 0;
                    cout<<"|---P"<<p[i].pid<<"---|";
                    cout<<t;
                    
                    c++;
                }
            }
        }
    }
    cout<<endl<<endl;
}

void RR::display()
{
   cout<<endl<<"Processes | "<<"Burst time | "<<"Complition time | "<<"Waiting time | "<<"Response time | "<<" Turn around time "<<endl;
      for(int i=0;i<num;i++)
       {
           wt=wt+p[i].waiting_time;
           tt=tt+p[i].turnAround_time;
           cout<<"P"<<p[i].pid<<setw(15)<<p[i].burst_time<<setw(15)<<p[i].complition_time<<setw(15)<<p[i].waiting_time<<setw(15)<<p[i].response_time<<setw(15)<<p[i].turnAround_time<<endl;
     }
     cout<<endl<<" Total waiting time : "<<wt<<endl;
     cout<<" Average waiting time : "<<(wt/num)<<endl;
     cout<<" Total turnaround time : "<<tt<<endl;
     cout<<" Average turnaround time : "<<(tt/num)<<endl;
}


int main()
{
    RR obj;
    obj.input();
    obj.calculate();
    obj.display();
   
    
    getch();
    return 0;
}
