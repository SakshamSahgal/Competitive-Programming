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
        lli n;
        cin>>n;
        lli a[n];
        lli len=1;

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli dp[n];
        map<lli,lli> ava;

        for(int i=n-1; i>=0; i--)
        {
            cout<<"at = "<<a[i]<<" \n";
            lli c=1;
            lli x = a[i];
            while(x != 0)
            {
                if(x%2 == 0)
                {
                    x/=2;
                    if(ava[x] != 0)
                    {
                        cout<<"x = "<<x<<" val = "<<ava[x]<<"\n";
                        c+=ava[x];
                    }
                }
                else
                {
                    if(ava[1] != 0)
                    {
                        cout<<"x = "<<1<<" val = "<<ava[1]<<"\n";
                        c+=ava[1];
                        break;
                    }
                    else
                        break;
                }

                if(x == 1)
                    break;
            }

                dp[i] = c;
                ava[a[i]] = c;
        }

        array_printer(dp,n);
        lli sum=0;
        for(int i=0; i<n; i++)
            sum += dp[i];
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}

