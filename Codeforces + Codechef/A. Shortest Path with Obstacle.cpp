#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int t;
cin>>t;
while(t)
{
    int ax,ay,bx,by,fx,fy;
    cin>>ax>>ay>>bx>>by>>fx>>fy;

    if(ax == bx) //same row
    {
        if(fx == ax && fy >= min(ay,by) && fy <= max(ay,by) )
            cout<<abs(by-ay) + 2<<"\n";
        else
            cout<<abs(by-ay)<<"\n";
    }
    else if(ay == by) //same col
    {
        if( fy == ay && fx >= min(ax,bx) && fx <= max(ax,bx) )
            cout<<abs(bx-ax) + 2<<"\n";
        else
            cout<<abs(bx-ax)<<"\n";
    }
    else
            cout<<abs(ax-bx) + + abs(ay-by)<<"\n";
    t--;
}

return 0;
}

