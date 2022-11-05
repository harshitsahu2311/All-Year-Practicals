#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>
using namespace std;
int main(int argc , char *argv[])
{
    char time[50];
    struct stat s;
    int fd;
    if(argc!=2)
    {
        cout<<"Wrong arguments";
        return 0;
    }
    
    fd=open(argv[1], O_RDONLY);
    fstat(fd,&s);
    
    cout<<"Owner ID : "<<s.st_uid<<"\n";
    cout<<"Group ID : "<<s.st_gid<<"\n";
    printf("Mode:%o(octal)\n",s.st_mode & 0777);
    strftime(time,sizeof (time) , "%d.%m.%Y.%H.%M.%S" , localtime(&s.st_atime));
    cout<<"Last access time = "<<time<<"\n";
    strftime(time,sizeof (time) , "%d.%m.%Y.%H.%M.%S" , localtime(&s.st_mtime));
    cout<<"Last modified time = "<<time<<"\n";
    
    return 0;
}
