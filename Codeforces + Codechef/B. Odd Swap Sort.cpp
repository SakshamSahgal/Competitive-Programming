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
        vector<lli> e;
        vector<lli> o;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2 == 0)
                e.push_back(a[i]);
            else
                o.push_back(a[i]);
        }
        if(e.size())
        {
            for(int i=1; i<e.size(); i++)
            {
                if(e[i] < e[i-1])
                {
                    cout<<"No\n";
                    goto l;
                }
            }
        }

        if(o.size())
        {
            for(int i=1; i<o.size(); i++)
            {
                if(o[i] < o[i-1])
                {
                    cout<<"No\n";
                    goto l;
                }
            }
        }
        cout<<"Yes\n";
l:
        t--;
    }
    return 0;
}

