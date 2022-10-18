#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    lli a[n];
    vector<lli> ps(n,0);
    vector<lli> ss(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];

    ps[n-1] = 0;
    ss[0] = 0;
    for(lli i=0; i<n-1; i++)
    {
        if(a[i] > a[i+1])
            ps[i] = a[i] - a[i+1];
    }

    for(lli i=n-1; i>0; i--)
    {
        if(a[i-1] < a[i] )
            ss[i] = a[i] - a[i-1];
    }
    lli s=0;
    for(lli i=0; i<n; i++)
    {
        s += ps[i];
        ps[i] = s;
    }
    s=0;
    for(lli i=n-1; i>=0; i--)
    {
        s += ss[i];
        ss[i] = s;
    }

    //vector_printer(ps);
    //vector_printer(ss);

    while(m--)
    {
        lli a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a < b)
        {
            b--;
            if(a == 0)
                cout<<ps[b]<<"\n";
            else
                cout<<ps[b] - ps[a-1]<<"\n";
        }
        else
        {
            b++;
            if(a == b)
                cout<<ss[a]<<"\n";
            else
            {
                if(a == n-1)
                    cout<<ss[b]<<"\n";
                else
                    cout<<ss[b] - ss[a+1]<<"\n";
            }
        }
    }

    return 0;
}

