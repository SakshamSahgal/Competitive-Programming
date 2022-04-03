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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        map<lli,vector<lli>> g;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g[a[i]].push_back(i);
        }

        sort(a,a+n);
        n = unique(a, a + n) - a;
        array_printer(a,n);
        lli mini = a[0];
        if(n == 1)
            cout<<mini<<"\n";
        else
        {
            for(int i=n-1;i>0;i--)
            {
                lli val = 0;
                vector<lli> temp = g[a[i]];
                for(auto j:g[mini])
                {
                    if(j > )
                    auto ptr = lower_bound(g[a[i]].begin(),g[a[i]].end(),j);
                    if(ptr == g[a[i]].end())
                    {
                        ptr--;
                        lli id = *ptr;

                    }
                    else if(ptr == g[a[i]].begin())
                    {

                    }


                }
            }
        }


        t--;
    }
    return 0;
}

