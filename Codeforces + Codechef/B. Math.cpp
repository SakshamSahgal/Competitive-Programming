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


vector<pair<lli,lli>> prime_factorisation(lli n)
{
    vector<pair<lli,lli>> p;
    if(n == 1)
        return p;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                int c=0;
                while(n%i == 0)
                {
                    n=n/i;
                    c++;
                }
                p.push_back({i,c});
            }
        }

        if(n != 1)
            p.push_back({n,1});

        return p;
    }
}

lli nearest_power_of_2(lli n)
{
    for(lli i=1; i<=1e6; i*=2)
    {
        if(i >= n)
            return i;
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;

    if(n==1)
    {
        cout<<1<<" "<<0<<"\n";
        return 0;
    }

    vector<pair<lli,lli>> pf = prime_factorisation(n);

    bool all_eq=1;
    lli mx = 0;

    for(int i=0; i<pf.size(); i++)
    {
        mx = max(mx,pf[i].second);
        if(pf[i].second != pf[0].second)
            all_eq = 0;
    }

    lli ans=0;
    lli npo2;


    npo2 = nearest_power_of_2(mx);

    if(!all_eq)
    {
        ans++;
        lli z = npo2;
        while(z != 1)
            z/=2,ans++;
    }
    else
    {
        if(mx != npo2)
            ans++;
        lli z = npo2;
        while(z != 1)
            z/=2,ans++;
    }
    //cout<<"mx = "<<mx<<" all eq = "<<all_eq<<" npo2 = "<<npo2<<" \n";

    lli nn=1;
    for(int i=0; i<pf.size(); i++)
        nn *= pf[i].first;

    cout<<nn<<" "<<ans<<"\n";
    return 0;
}

