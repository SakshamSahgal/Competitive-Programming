#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

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
        vector<lli> d(n);
        vector<lli> a(n);
        lli s=0;

        for(int i=0; i<n; i++)
        {
            cin>>d[i];
            s += d[i];
        }

        if(n == 1)
            cout<<d[0]<<"\n";
        else
        {
            s -= d[0];
            s -= 2*d[n-1];
            if(s > 0)
                cout<<-1<<"\n";
            else
            {
                a[0] = d[0];
                for(int i=0; i<n-1; i++)
                    a[i+1] = a[i] + d[i+1];
                for(int i=0; i<n; i++)
                    cout<<a[i]<<" ";
                cout<<"\n";
            }
        }


        t--;
    }
    return 0;
}

