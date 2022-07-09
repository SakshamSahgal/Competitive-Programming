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

        lli n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        if(n == 1)
        {
            cout<<"1 1"<<"\n";
            cout<<(-a[0])<<"\n";
            cout<<"1 1"<<"\n";
            cout<<0<<"\n";
            cout<<"1 1"<<"\n";
            cout<<0<<"\n";
        }
        else
        {
            cout<<"1 "<<n<<"\n";
            for(int i=0;i<n;i++)
                cout<<(-a[i]*n)<<" ";
            cout<<"\n";
            cout<<"1 "<<n-1<<"\n";
            for(int i=0;i<n-1;i++)
                cout<<(a[i]*(n-1))<<" ";
            cout<<"\n";
            cout<<n<<" "<<n<<"\n";
            cout<<(a[n-1]*(n-1))<<"\n";
        }
    return 0;
}
