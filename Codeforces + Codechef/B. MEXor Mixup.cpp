#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

lli xorr[300001];

int main()
{
    lli xx = 0;
    for(int i=0; i<=300000; i++)
    {

             xx = xx^i;
             //  cout<<"i = "<<i<<" ";
             // cout<<xx<<"\n";
             xorr[i] = xx;

    }
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        /*
        cout<<"\n";
        for(int i=0;i<a;i++)
            cout<<xorr[i]<<" ";
        cout<<"\n"; */



        if(xorr[a-1] == b)
            cout<<a<<"\n";
        else
        {
            if( ((xorr[a-1])^b) == a)
                cout<<a+2<<"\n";
            else
                cout<<a+1<<"\n";
        }

        t--;
    }
    return 0;
}
