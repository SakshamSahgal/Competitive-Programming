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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli p[n];
        bool occ[n];
        map<lli,lli> y;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            occ[i] = 0;
            y[p[i]] = i;
        }
        occ[y[1]] = 1;
        lli last = 1;
        for(int i=2;i<=n;i++)
        {
            //cout<<"Checking for "<<i<<"\n";
            if(y[last] + 1 < n && occ[y[last] + 1] == 0)
            {
                if(y[i] != y[last] + 1)
                {
                    cout<<"No\n";
                    goto l;
                }
                else
                {
                    //cout<<"ok \n";
                    occ[y[i]] = 1;
                    last = i;
                }
            }
            else
            {
                occ[y[i]] = 1;
                last = i;
            }
            //array_printer(occ,n);
        }
        cout<<"Yes\n";
        l:
        t--;
    }
    return 0;
}

