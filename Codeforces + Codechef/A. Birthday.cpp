#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
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

    lli n;
    cin>>n;
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);
    stack<lli> x;
    lli b[n];

    for(int i=0; i<n; i++)
        x.push(a[i]);

    lli j=0;
    while(!x.empty())
    {
        if(j == 0)
        {
            b[(n/2-j)] = x.top();
            x.pop();
        }
        else
        {
            if( (n/2-j) >= 0 && !x.empty())
            {
                b[(n/2-j)] = x.top();
                x.pop();
            }
            if( n/2 + j < n && !x.empty())
            {
                b[(n/2+j)] = x.top();
                x.pop();
            }
        }
        j++;
    }

    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";
    cout<<"\n";

    return 0;
}

