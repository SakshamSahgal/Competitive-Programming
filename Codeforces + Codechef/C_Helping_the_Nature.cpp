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


int main(){
    //GO_FAST̥
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        lli moves=0;
        lli s=0;
        for(int i=0;i<n-1;i++)
        {
            lli tv = a[i] + s;
            lli nv = a[i+1] + s;
            if(tv > nv)
                moves += abs(tv - nv);
            else if(tv < nv)
            {
                moves += abs(tv - nv);
                s -= (abs(tv - nv));
            }
        }

        if(s + a[n-1] != 0)
         moves += abs(s + a[n-1]);
        cout<<moves<<"\n";
        t--;
    }
    return 0;
}