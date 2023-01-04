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


void set_printer(set<lli> x)
{
    for(auto i:x)
        cout<<i<<" ";
    cout<<"\n";
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
        lli n,k,m;
        cin>>n>>k>>m;
        vector<lli> r(n);
        for(int i=0; i<n; i++)
            cin>>r[i];
        lli ans = inf;
        lli mx_pw = powl(2,n);

        for(lli i=0; i<mx_pw; i++)
        {
            //cout<<"i = "<<i<<"\n";
            vector<lli> z = r;
            lli noo=0;
            for(lli j=0; j<n; j++)
            {
                if( (i>>j)%2 )
                    z[j]++,noo++;
            }
            //vector_printer(z);
            map<lli,lli> f;
            int l=0;
            int r=0;
            bool fail=0;
            set<lli> mx;
            while(r<n)
            {
                f[z[r]]++;
                mx.insert(z[r]);

                while(r-l+1<k)
                {
                    r++;
                    f[z[r]]++;
                    mx.insert(z[r]);
                }

                //cout<<"{l = "<<l<<" r = "<<r<<"} ["<<(*mx.rbegin())<<"] ";
                //set_printer(mx);

                if(f[(*mx.rbegin())] >= m)
                {
                    fail=1;
                    break;
                }

                f[z[l]]--;
                if(f[z[l]] == 0)
                    mx.erase(mx.find(z[l]));
                l++;
                r++;
            }

            if(!fail)
            {
                //cout<<"Found at = "<<i<<" noo = "<<noo<<"\n";
                ans = min(ans,noo);
            }
        }
        if(ans==inf)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
        t--;
    }
    return 0;
}

