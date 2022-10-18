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

bool yes(vector<lli> &mx,lli len,lli k)
{
    if(mx[len-1] <= k)
        return 1;
    else
        return 0;
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
        lli n,q;
        cin>>n>>q;
        lli a[n];
        vector<lli> ps(n);
        vector<lli> mx(n);
        lli maxx = -inf;
        lli s=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            maxx = max(a[i],maxx);
            mx[i] = maxx;
            s += a[i];
            ps[i] = s;
        }

        while(q--)
        {
            lli k;
            cin>>k;

            lli l=1;
            lli h=n;
            lli ans=0;
            while(l<=h)
            {
                lli mid = (l+h)/2;
                if(yes(mx,mid,k))
                {
                    ans = mid;
                    l = mid+1;
                }
                else
                    h = mid-1;
            }

            if(ans == 0)
                cout<<0<<" ";
            else
                cout<<ps[ans-1]<<" ";
        }
        cout<<"\n";
        t--;
    }
    return 0;
}

