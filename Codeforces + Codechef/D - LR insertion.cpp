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
    lli n;
    cin>>n;
    lli x[n+1][2];

    for(int i=0;i<n+1;i++)
    {
        x[i][0] = -1;
        x[i][1] = -1;
    }

    string s;
    cin>>s;

    for(int i=0;i<n;i++)
    {
        if(s[i] == 'L')
        {
            if(x[i][0] == -1)
            {
                x[i][0] = i+1;
                x[i+1][1] = i;
            }
            else
            {
                x[i+1][0] = x[i][0];
                x[x[i][0]][1] = i+1;
                x[i+1][1] = i;
                x[i][0] = i+1;
            }
        }
        else
        {
            if(x[i][1] == -1)
            {
                x[i][1] = i+1;
                x[i+1][0] = i;
            }
            else
            {
                x[i+1][1] = x[i][1];
                x[x[i][1]][0] = i+1;
                x[i+1][0] = i;
                x[i][1] = i+1;
            }
        }
    }

    //for(int i=0;i<n+1;i++)
       // cout<<x[i][0]<<" "<<x[i][1]<<"\n";

    lli st;

    for(int i=0;i<=n;i++)
    {
        if(x[i][0] == -1)
        {
            st = i;
            break;
        }
    }

    lli cur = st;

    while(cur != -1)
    {
        cout<<cur<<" ";
        cur = x[cur][1];
    }
    cout<<"\n";
    return 0;
}

