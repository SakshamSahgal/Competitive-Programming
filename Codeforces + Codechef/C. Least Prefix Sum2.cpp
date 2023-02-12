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
        lli a[n+1];
        for(int i=1; i<=n; i++)
            cin>>a[i];
        lli ans=0;

        if(m != 1)
            if(a[m] > 0)
                a[m] *= -1,ans++;

        if(m+1 <= n)
            if(a[m+1] < 0)
                a[m+1]*=-1,ans++;


        lli s=a[m];
        priority_queue<pll> z;

        for(int i=m-1; i>1; i--)
        {
            if(a[i] > 0)
            {
                z.push({a[i],i});
                if(a[i] + s > 0)
                {
                    a[z.top().second] *= -1; //neg

                    if(z.top().second != i)
                        s += 2*a[z.top().second];
                    s += a[i];
                    z.pop();
                    ans++;
                }
                else
                    s += a[i];
            }
            else
                s += a[i];
        }



        s = a[m+1];
        z = priority_queue <pll>(); // reset it
        for(int i=m+2;i<=n;i++)
        {
            if(a[i] < 0)
            {
                z.push({abs(a[i]),i});
                if(a[i] + s < 0)
                {
                    a[z.top().second] *= -1; //pos

                    if(z.top().second != i)
                        s += 2*a[z.top().second];
                    s += a[i];
                    z.pop();
                    ans++;
                }
                else
                    s += a[i];
            }
            else
                s += a[i];
        }
        /*
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n"; */
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

