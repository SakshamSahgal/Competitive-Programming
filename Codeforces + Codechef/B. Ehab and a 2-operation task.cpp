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

    lli n;
    cin>>n;
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    lli s=0;
    vector<pair<lli,pair<lli,lli>>> v;
    for(int i=n-1; i>=0; i--)
    {
        lli to_add = 0;
        if((a[i]+s)%n != i)
        {
            lli nm;

            if( (a[i]+s)%n == 0 )
                nm = (a[i]+s);
            else
                nm = ((a[i]+s)/n + 1)*n;

           // cout<<"nearest multiple = "<<nm<<"\n";

            to_add = (nm + i) - (a[i] + s);

          //  cout<<" val = "<<(a[i]+s)<<" to add = "<<to_add<<"\n";
            v.push_back({1,{i+1,to_add}});
            s += to_add;
        }
    }

    v.push_back({2,{n,n}});
    cout<<v.size()<<"\n";

    for(auto i:v)
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";

    return 0;
}
