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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
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
        lli m=0;
        for(int i=0; i<n; i++)
            cin>>a[i];

        vector<pair<lli,pair<lli,lli>>> v;

        if( a[n-2] <= a[n-1] )
        {
            if( (a[n-2] <= 0 && a[n-1] >= 0) || (a[n-2] >= 0 && a[n-1] >= 0) )
            {
                for(int i=n-3; i>=0; i--)
                {
                    if( a[i] > a[i+1] )
                    {
                        m++;
                        a[i] = a[i+1] - a[n-1];
                        v.push_back({i+1,{i+2,n}});
                    }
                }

                cout<<m<<"\n";
                for(auto i:v)
                    cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
            }
            else
            {
                for(int i=n-3; i>=0; i--)
                {
                    if( a[i] > a[i+1] )
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                }

                cout<<m<<"\n";
                for(auto i:v)
                    cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
            }
        }
        else
            cout<<"-1\n";
l:
        t--;
    }
    return 0;
}
