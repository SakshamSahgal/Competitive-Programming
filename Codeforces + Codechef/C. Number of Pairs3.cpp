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
        lli n,l,r;
        cin>>n>>l>>r;
        vector<lli> a(n);

        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a.begin(),a.end());
        lli sum=0;
        for(int i=0;i<n;i++)
        {
            lli at_least = l - a[i];
            lli at_most = r - a[i];
            auto st = lower_bound(a.begin()+i+1,a.end(),at_least);
            auto ed = upper_bound(a.begin()+i+1,a.end(),at_most);
            //cout<<"at i = "<<i<<" atleast = "<<at_least<<" atmost = "<<at_most<<" st = "<<(st - a.begin())<<" ed = "<<(ed-a.begin())<<"\n";
            sum += (ed-st);
        }
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}

