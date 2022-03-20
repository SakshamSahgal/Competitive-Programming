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

lli factorial(lli n)
{
    lli res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

vector<lli> fac;

lli bit_set(lli n)
{
    lli c=0;
    for(lli i=0; i<=39; i++)
    {
        lli set_a = ((n>>i)%2);
        if(set_a)
            c++;
    }
    return c;
}

int main()
{
    GO_FAST

    for(lli i=1; i<=14; i++)
        fac.push_back(factorial(i));

    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli ans=bit_set(n);
        for(lli i=0; i<=16383; i++)
        {
            lli sum=0;
            lli no=0;
            for(lli j=0; j<14; j++)
            {
                lli set_a = ((i>>j)%2);
                if(set_a)
                {
                    no++;
                    sum += fac[j];
                    //cout<<"taking "<<fac[j]<<" ";
                }
            }
            if(sum <= n)
                ans = min(ans,bit_set(n-sum) + no);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

