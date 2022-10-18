#include<unistd.h>
#include<bits/stdc++.h>
#include<sys/resource.h>
using namespace std;
int main()
{
    int val = fork();
    if(val == 0)
    {
        setpriority(PRIO_PROCESS, 0,19);
        cout<<"Hello i am child and my id = "<<getpid()<<" my parent id = "<<getppid()<<"\n";
    }
    else if(val > 0)
        cout<<"Hello i am parent and my id = "<<getpid()<<" and my child id = "<<val<<"\n";
    return 0;
}
