#include<pthread.h>
#include<stdio.h>
#include<thread>
#include<iostream>
#include<cstdlib>
using namespace std;

void *print(void *p);

int main(int argc, char **argv)
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    if(argc!=2) {
        cout<<"Error you have give wrong argument \n";
        return -1;
    }

    if(atoi(argv[1])< 0) {
        cout<<"\n Integer value must be greater than 0.\n";
        return -1;
    }
    
    int a = atoi(argv[1]);
    
    pthread_create(&tid , &attr , print , &a);
    pthread_join(tid , NULL);
    
    return 0;
}

void *print(void *p)
{
    int i ; 
    int num = *(int*)(p);
    int sum  = 0;
    cout<<"\nI am inside a thread function \n"<<endl;
    for(i=1;i<=num;i++)
    sum += i;
    
    cout<<"Sum is : "<<sum<<endl<<endl;
    pthread_exit(0);
}
