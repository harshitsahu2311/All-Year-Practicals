#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int pid,at,bt,rt,wt,tat,ct,st;
};

class sjf{
    int n;
    float avg_wt,avg_rt,avg_tat;
    Process *p;
      public:
        sjf()
        {
            avg_wt = 0;
            avg_tat=0;
            avg_rt=0;
        }
        void input();
        void display();
        void calculate();
        void sort();
        void sort_burst(int,int);

};

void sjf ::input()
{
    cout<<endl<<"Enter total processes: ";
    cin>>n;

    p = new Process[n];
    cout<<endl<<"Enter Pid: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>p[i].pid;
    }

    cout<<endl<<"Enter the arrival times: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>p[i].at;
    }

    cout<<endl<<"Enter the burst times: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>p[i].bt;
    }

}

void sjf::calculate()
{
    for(int i=0;i<n;i++)
    {
      

        p[i].st = (i==0)?p[i].at:max(p[i].at,p[i-1].ct);
        p[i].ct= p[i].st + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;                  
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt = p[i].st-p[i].at;

        avg_wt+=  p[i].wt;
        avg_rt+=  p[i].rt;
        avg_tat+= p[i].tat;
    }

    avg_wt /= n;
    avg_wt /= n;
    avg_tat /= n;
}
void sjf::sort()
{
  int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            
            if(p[j].at>p[j+1].at)
            {
                swap(p[j],p[j+1]);    

            }

          
        }
    }
int counter = 0;


for(i=0;i<n;i++)
{
    if(p[0].at == p[i].at)
    {
        counter++;
    }
}


for(i=0;i<counter;i++)
{
  for(j=0;j<counter-1-i;j++)
  {
      if(p[j].bt>p[j+1].bt)
            swap(p[j],p[j+1]);
  }
}


    for(j=0;j<n;j++)
    {
          

          p[j].st = (j==0)?p[j].at:max(p[j].at,p[j-1].ct);
                 p[j].ct= p[j].st + p[j].bt;

                for(i=j;i<n;i++)
                { if(p[j].ct<p[i+1].at)
                  break;
                } 

              sort_burst(j+1,i);
        }
    }

    void sjf :: sort_burst(int start, int end)
    {
    Process *temp = new Process[end-start+1];

        int i,j;
            for(j=0,i=start;i<=end;i++)
            {
                temp[j] = p[i]; 
                j++; 
            }

     for(i=0;i<end-start+1;i++)
     {
        for(j=0;j<end-start-i;j++)
        {
            
            if(temp[j].bt>temp[j+1].bt)
            {
                swap(temp[j],temp[j+1]);   

            }
        }


     }

         for(j=0,i=start;i<=end;i++)
            {
                p[i] = temp[j++]; 
            }

    delete temp;

    }

void sjf::display()
{
    cout<<endl<<"\t\t\t\t\t:GANTT CHART:";
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<p[i].pid<<"\t";
    }
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    cout<<p[0].at;
    for(int i=0;i<n;i++)
    {
        cout<<"\t\t"<<p[i].ct;
    }  

    cout<<endl<<endl<<"Process' \tProcess ID \tArrival Time \tBurst Time \tWaiting Time \tCompletion Time \tTurnaround Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"] \t\t  "<<p[i].pid<<"\t\t  "<<p[i].at<<"\t\t  "<<p[i].bt<<"\t\t  "<<p[i].wt<<"\t\t  "<<p[i].ct<<"\t\t\t\t"<<p[i].tat<<endl;
    }

    cout<<endl<<endl;
    cout<<"Average Waiting Time \t\t Average Response Time \t\t Average Turnaround Time \t\t \n";
    cout<<"\t"<<avg_wt<<"\t\t\t\t"<<avg_rt<<"\t\t\t\t"<<avg_tat<<endl;
    
}

int main()
{
    sjf ob1;
   
    ob1.input();
     ob1.sort();
    ob1.calculate();
    ob1.display();

    
    return 0;
}
