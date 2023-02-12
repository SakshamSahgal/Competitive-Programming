#include<bits/stdc++.h>
#define lli long long int
#define ulli unsigned long long int
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


ulli range(ulli left, ulli right)
{
    ulli i=0;

    while(left!=right)
    {
        i++;
        left>>=1;
        right>>=1;

    }
    return left<<i;
}

bool is_set(ulli n,ulli r)
{

    bool ans = (n>>r)%2;
    return ans;
}

int main()
{
    //cout<<range(10,4375000000000000002)<<"\n";
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        ulli n,x;
        cin>>n>>x;

        ulli l=n;
        ulli h=5e18;
        ulli m=inf;

        for(ulli i=0;i<=63;i++)
        {
            if(is_set(n,i) == 0 && is_set(x,i) == 1)
            {
                cout<<"-1\n";
                goto l;

            }
        }

        while(l<=h)
        {
            ulli mid = l + ((h - l) / 2);
            //cout<<l<<" "<<h<<" "<<mid<<"\n";
            ulli th = range(n,mid);
            cout<<"trying mid = "<<mid<<" th = "<<th<<" ";
            if(th == x)
            {
                cout<<" poss\n";
                m = th;
                h = mid-1;
            }
            else
            {
                cout<<" not poss\n";
                l = mid+1;
            }
        }

        if(m == inf)
            cout<<-1<<"\n";
        else
            cout<<m<<"\n";

        l:
        t--;
    }
    return 0;
}

