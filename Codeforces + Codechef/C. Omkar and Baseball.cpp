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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli a1[n];
        bool b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            a1[i] = a[i];
        }

        sort(a1,a1+n);
        lli match=0;
        for(int i=0; i<n; i++)
        {
            if(a[i] == a1[i])
            {
                match++;
                b[i] = 1;
            }
            else
                b[i] = 0;
        }
        if(match == n)
            cout<<0<<"\n";
        else
        {
           n = unique(b,b+n) - b;
           lli noz=0;
           for(int i=0;i<n;i++)
           {
               //cout<<b[i]<<" ";
               if(b[i] == 0)
                noz++;
           }

        cout<<min((lli)2,noz)<<"\n";
        }
        t--;
    }
    return 0;
}
