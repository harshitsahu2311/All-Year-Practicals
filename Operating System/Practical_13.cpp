#include<iostream>
using namespace std;
class Allocation_Strategies
{

    int block_no;
    int process_no;
    int smallest;
    int b_id[100];
    int p_id[100];
    int block[100];
    int process[100];
    int flag[100];
    int allocation[100];
    
    public:
    void input();
    void Best_Fit();
    void Worst_Fit();
    void First_Fit();
    void choice();
    void output();
    void sort_w();
    Allocation_Strategies()
    {
    
        for(int i=0;i<100;i++)
        {
            flag[i] = 0;
            allocation[i] = -1;
        }

    }

    
};

void Allocation_Strategies :: input()
{
    
       cout<<endl<<"  Enter the number of blocks : ";


       cin>>block_no;

       cout<<endl<<"  Enter size of each block : "<<endl;
        cout<<endl;
        for(int i=0;i<block_no;i++)
        {
            cout<<"  Block "<<i+1<<" : ";
            cin>>block[i];
            

        }
        
        cout<<endl<<"  Enter the number of processes : ";
        cin>>process_no;

        
        cout<<endl<<"  Enter each process size : "<<endl;
        cout<<endl;
        for(int i=0;i<process_no;i++)
        {
            cout<<"  Process "<<i+1<<" : ";
             cin>>process[i];    
        }
        
        for(int i=0;i<process_no;i++)
        {
            p_id[i]=i+1;
        }
           for(int i=0;i<block_no;i++)
        {
            b_id[i]=i+1;
        }
}



void Allocation_Strategies :: output()
{
        cout<<"  \n  Block no.\tSize\t\tProcess no.\t\tSize";

          for(int i=0;i<block_no;i++)
          {
            cout<<"  \n  "<<"  "<<i+1<<"\t\t"<<"  "<<block[i]<<"\t\t";
            
              if(flag[i] == 1)
              cout<<"  "<<allocation[i]+1<<"\t\t\t"<<"   "<<process[allocation[i]];

              else
            cout<<"Not allocated";

          }
}


void Allocation_Strategies :: First_Fit()
{
        for(int i=0;i<process_no;i++)
        {
             for(int j=0;j<block_no;j++)
             {
                 if(flag[j] == 0 && block[j] >= process[i])
                 {
                      allocation[j] = i;
                      flag[j] = 1;
                      break;
                }
             }
        }

}


void Allocation_Strategies :: Best_Fit()
{
    int j , i;
    for(i=0;i <process_no;i++)
    {
        smallest=-1;
        for(j=0;j<block_no;j++)
            if(flag[j]==0 && block[j] >= process[i])
            {
                smallest=j;
                break;
            }
            
        for(;j < block_no;j++)
            if(flag[j]==0 && block[j] >= process[i] && block[j] < block[smallest])
                smallest=j;
                
        if(smallest!=-1)
        {
            allocation[smallest]=i;
            flag[smallest]=1;
        }
    }
}

void Allocation_Strategies :: sort_w()
 {
     for (int i=1,j;i<block_no;i++) 
    {
         int temp = block[i];
     
         int t = b_id[i];
         for (j=i;j>0;j--)
        {
            if(temp < block[j-1])
                break;
            else
            {
                b_id[j] = b_id[j-1];
                block[j] = block[j-1];
            }
        }
        block[j] = temp;
        b_id[j] = t;
    }
 }
void Allocation_Strategies :: Worst_Fit()
{
    sort_w();
    
    for(int i=0;i<process_no;i++)
     {
         for(int j=0;j<block_no;j++)
         {
             if(process[i] <= block[j])
             {
                 block[j] -= process[i];
                 cout<<endl<<"  Process "<<p_id[i]<<" got memory allocated in Block "<<b_id[j];
                 sort_w();
                 break;
            }
        }
    }
}


void Allocation_Strategies :: choice()
{
    int n;
    char c;
    
    do
    {
        cout<<endl<<endl;
        cout<<"  Press 1 for First-Fit strategies "<<endl;
        cout<<"  Press 2 for Best-Fit strategies "<<endl;
        cout<<"  Press 3 for Worst-Fit strategies "<<endl;
        cout<<endl<<endl<<"  Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1:
                input();
                First_Fit();
                output();
                break;
                
            case 2:
                input();
                Best_Fit();
                output();
                break;
                
            case 3:
                input();
                Worst_Fit();
                
                break;
                
            default:
                cout<<endl<<"  Entered correct choice"<<endl;
        }
        cout<<endl<<endl<<"  Do you want to continue press (y/n) ? : ";
        cin>>c;
            
    }while(c=='Y'||c=='y');
    
}

int main()
{
    cout<<endl<<"~~~~~~~~~~~~~~~ FIRST, BEST, WORST MEMEORY FIT ALLCOATION STRATEGIES ~~~~~~~~~~~~~"<<endl<<endl;
    
    Allocation_Strategies ob;
    ob.choice();
    return 0;
    
}
