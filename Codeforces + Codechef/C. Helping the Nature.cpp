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
        lli n;
        cin>>n;
        lli a[n];
        bool allz = 1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] != 0)
                allz = 0;
        }
        if(allz)
            cout<<0<<"\n";
        else
        {
            lli mini;
            lli moves=0;
            if(a[0] >= 0)
            {
                mini = 0;
                moves += (a[0]);
            }
            else
            {
                mini = a[0];
            }

            lli s=0;
            cout<<"i = "<<0<<" mini = "<<mini<<" moves = "<<moves<<"s = "<<s<<"\n";
            for(int i=1;i<n;i++)
            {
                lli th = a[i] + s;
                if(th < mini)
                {
                    moves +=abs(mini - th);
                    mini = th;
                }
                else
                {
                    moves += abs(mini - th);
                    s -= abs(mini - th);
                }
                cout<<"i = "<<i<<" mini = "<<mini<<" moves = "<<moves<<"s = "<<s<<"\n";
            }

            moves += abs(0 - (s + a[n-1]) );
            cout<<moves<<"\n";
        t--;
    }
    }
    return 0;
}
