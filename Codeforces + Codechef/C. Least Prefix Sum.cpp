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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n];
        vector<lli> ps(n);
        lli ans=0;
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(a[m-1] > 0 && m != 1)
        {
            ans++;
            a[m-1] *=-1;
        }

        lli s = a[m-1];
        priority_queue<pll> zz; //max heap
        for(int i=m-2; i>=0; i--)
        {
            if(a[i] > 0)
            {
                zz.push({a[i],i});
                if(a[i] + s > 0)
                {
                    a[zz.top().second] *= -1;
                    s += 2*a[zz.top().second];
                    ans++;
                    if(zz.top().second != i)
                        s += a[i];
                    zz.pop();
                }
                else
                    s += a[i];
            }
            else
                s += a[i];
        }

        if(m < n)
        {
            priority_queue<pll> z;

            if(a[m] < 0)
            {
                ans++;
                a[m] *=-1;
            }

            s = a[m];

            for(int i=m+1; i<n; i++)
            {
                if(a[i] < 0)
                {
                    z.push({abs(a[i]),i});
                    if(s + a[i] < 0)
                    {
                        a[z.top().second] *= -1;
                        s += 2*a[z.top().second];
                        ans++;
                        if(zz.top().second != i)
                            s += a[i];
                        z.pop();
                    }
                    else
                        s += a[i];
                }
                else
                    s += a[i];
            }
        }
        array_printer(a,n);
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}
