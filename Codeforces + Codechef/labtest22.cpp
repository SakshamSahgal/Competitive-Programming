#include<bits/stdc++.h>
#include<unistd.h>
#include<wait.h>
using namespace std;
int main()
{
    int p[2];

    pipe(p);

    pid_t val = fork();

    if(val == 0) //child
    {
        char ln[20];
        char gfn[20];
        cout<<"enter last name : ";
        cin>>ln;
        read(p[0],gfn,7);
        char fln[40];
        int j=0;
        for(int i=0;i<7;i++)
            fln[j++] = gfn[i];

        fln[j++] = " ";

        for(int i=0;i<strlen(ln);i++)
            fln[j++] = ln[i];

        write(p[1],fln,j);
    }
    else if(val > 0) //p1 (parent)
    {
        char fn[20];
        char gfln[40];
        cout<<"enter fn : ";
        cin>>fn;
        write(p[1],fn,strlen(fn));
        wait(NULL);
        read(p[0],gfln,14);
        cout<<gfln<<"\n";
    }
    else
        cout<<"Error\n";

    return 0;
}
