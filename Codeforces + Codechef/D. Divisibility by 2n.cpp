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

lli noz(lli x)
{
    lli c=0;
    for(lli j=0; j<=32; j++)
    {
        lli is_Set = (x>>j)%2;
        if(!is_Set)
            c++;
        else
            return c;
    }
    return c;
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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli have=0;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            have += noz(a[i]);
        }
        lli req = n - have;
        //cout<<"have = "<<have<<" req = "<<req<<"\n";
        if(req <= 0)
            cout<<0<<"\n";
        else
        {
            vector<lli> z;
            lli mx=0;
            for(int i=2; i<=n; i+=2)
            {
                lli zero = noz(i);
                z.push_back(zero);
                mx += zero;
            }
            if(mx < req)
                cout<<"-1\n";
            else
            {
                sort(z.begin(),z.end(),greater<lli>());
                lli ans=0;
                //vector_printer(z);
                for(int i=0;i<z.size();i++)
                {
                    if(req <= 0)
                        break;
                    else
                    {
                        req -= z[i];
                        ans++;
                    }
                }
                cout<<ans<<"\n";
            }
        }

        t--;
    }
    return 0;
}

