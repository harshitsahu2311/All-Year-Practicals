#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;



int main()
{
    cout<<"SAME PROGRAM D/F CODE : "<<endl;
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        system("ls");
    }
    else if(pid<0)
    {
        cout<<"Error , Child Not Created"<<endl;
    }

    else
    {
        system("ls -l");
    }
    
    
    return 0;
}
