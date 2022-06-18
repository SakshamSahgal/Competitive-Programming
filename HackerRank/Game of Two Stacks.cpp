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
        lli n,m,mx;
        cin>>n>>m>>mx;
        lli a[n],b[m];

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<m; i++)
            cin>>b[i];

        lli s=0;

        lli i=-1,j=-1;
        lli ct=0;
        lli ans=0;

        while( i+1 < n && (s + a[i+1] <= mx) )
        {
            s += a[i+1];
            ct++;
            i++;
        }

        do
        {
           // cout<<"ct = "<<ct<<"\n";
            while( j+1 < m && (s + b[j+1] <= mx) )
            {
                s += b[j+1];
                ct++;
                j++;
            }
           // cout<<"ct = "<<ct<<"\n";
            ans = max(ct,ans);

            if(i >= 0)
            {
                s -= a[i];
                i--;
                ct--;

                while( j+1 < m && (s + b[j+1] <= mx) )
                {
                    s += b[j+1];
                    ct++;
                    j++;
                }
                //cout<<"ct = "<<ct<<"\n";
                ans = max(ct,ans);
            }
        }
        while(i >= 0);

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
