#include&lt;stdio.h&gt;
#include&lt;sys/sysinfo.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;sys/utsname.h&gt;
using namespace std;

int main()
{
    int p = 0 , q = 0;
    struct sysinfo un;
    p = sysinfo(&amp;un);
    
    struct utsname s1;
    
    q = uname(&amp;s1);

    
    if(p==0 &amp;&amp; q==0)
    {
        printf("\n Kerner version : %s", s1.version);
    


        printf("\n Total RAM : %ld MB \n", (un.totalram));
        printf("\n Free RAM : %ld MB \n", (un.freeram));
        printf("\n Used RAM : %ld MB \n", (un.totalram-un.freeram));

    }
    
    else
    {
        printf("Error");
    }    
    
    return 0;
}
