#include<iostream>
#include<cmath>
using namespace std;
int main()
{
unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned int time = 0;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1 != x2)
        time = abs(x2-x1);

    else
    {
        if(y1 != y2)
        {
            time = abs(y2-y1);
            cout<<time<<"\n";
            goto y;
        }

    }

        if(y1 == y2)
        {
        cout<<time<<"\n";
        goto y;
        }
        else
        {
        time+=2;
        time+=abs(y2-y1);
        cout<<time<<"\n";
        goto y;
        }
        y:
        time = 0;

    }
return 0;
}
