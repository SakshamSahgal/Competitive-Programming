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
        lli a[n];
        multiset<lli> y;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            y.insert(a[i]);
        }
        lli x;
        cin>>x;
        lli ans=0;
        while(!y.empty())
        {
            auto ptr = y.begin();
            lli c1 = *ptr;
            y.erase(ptr);
            lli c2 = (c1^x);
            auto ptr2 = y.find(c2);
            if(ptr2 != y.end())
                y.erase(ptr2);
            else
                ans++;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

