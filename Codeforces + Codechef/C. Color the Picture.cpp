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

bool check1(lli r,lli c,lli a[],lli k)
{
    lli cr=c;
    bool found=0;
    for(int i=0; i<k; i++)
    {
        if(cr <= 0)
            break;
        //cout<<"a["<<i<<"] = "<<a[i]<<"\n";
        lli mxc = a[i]/r;
        if(mxc >= 2)
        {
            if(cr == 1)
            {
                if(found)
                {
                    cr = 0;
                    break;
                }
                else
                    break;
            }
            else
            {
                //cout<<"taking = "<<min(cr,mxc)<<"\n";
                if(min(cr,mxc) > 2)
                    found = 1;
                cr -= mxc;
            }
        }
        else
            break;
    }

    if(cr <= 0)
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
        lli n,m,k;
        cin>>n>>m>>k;
        lli a[k];
        for(int i=0; i<k; i++)
            cin>>a[i];
        sort(a,a+k,greater<lli>());
        if(check1(n,m,a,k) || check1(m,n,a,k))
            cout<<"Yes\n";
        else
            cout<<"No\n";
        t--;
    }
    return 0;
}

