#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

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
        string s;
        vector<lli> psp(n);
        vector<lli> psm(n);
        cin>>s;
        if(s[0] == '+')
        {
            psp[0] = 1;
            psm[0] = 0;
        }
        else
        {
            psp[0] = 0;
            psm[0] = 1;
        }

        for(lli i=1;i<n;i++)
        {
            if(s[i]== '+')
            {
                 psp[i] = psp[i-1] + 1;
                 psm[i] = psm[i-1];
            }
            else
            {
                psp[i] = psp[i-1];
                psm[i] = psm[i-1] + 1;
            }
        }
        lli ans=0;

        for(lli i=0;i<n;i++)
        {
            for(lli j=i;j<n;j++)
            {
                lli nom = sum_btw(psm,i,j);
                lli nop = sum_btw(psp,i,j);
                //cout<<"i = "<<i<<" j = "<<j<<" nom = "<<nom<<" nop = "<<nop<<"\n";
                if( nom >= nop && (nom-nop)%3 == 0)
                    ans++;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

