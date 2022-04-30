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
    lli b[n] = {0};
    for(int i=0; i<n; i++)
        cin>>a[i];
    lli mini = inf;
    for(lli i=0; i<n; i++)
    {
        lli sum=0;
        lli temp[n];
        temp[i] = 0;
        lli z=0;
        for(lli j=i-1; j>=0; j--)
        {
            lli z;
            z = abs(temp[j+1])/a[j] + 1;
            temp[j] = -z*a[j];
            sum += z;
        }

        for(int j=i+1;j<n;j++)
        {
            lli z;
            z = abs(temp[j-1])/a[j] + 1;
            temp[j] = z*a[j];
            sum += z;
        }
        //array_printer(temp,n);
        //cout<<"moves = "<<sum<<"\n";
        mini = min(mini,sum);
    }
    cout<<mini<<"\n";
    return 0;
}
