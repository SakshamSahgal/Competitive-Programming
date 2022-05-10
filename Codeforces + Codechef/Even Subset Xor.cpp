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

void calc(vector<lli> &x)
{
    for(int i=0;i<17;i++)
    {
        for(int j=i+1;j<18;j++)
        {
            for(int k=j+1;k<19;k++)
            {
                for(int l=k+1;l<20;l++)
                {
                    lli v = (1<<l) + (1<<k) + (1<<j) + (1<<i);
                    x.push_back(v);
                }

                if(x.size() == 1000)
                    break;
            }

            if(x.size() == 1000)
                    break;
        }
        if(x.size() == 1000)
                    break;
    }
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> x;
        calc(x);
        for(int i=0;i<n;i++)
            cout<<x[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

