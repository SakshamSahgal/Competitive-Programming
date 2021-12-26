#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli k,x;
        cin>>k>>x;

        if(x >= k*k )
            cout<<setprecision(18)<<(2*k - 1)<<"\n";
        else
        {
            if(  x <= (k*(k+1))/2 )
            {
               long double d = sqrtl((8*x + 1));
                cout<<(lli)ceil((d - 1)/2.0)<<"\n";
            }
            else
            {
                lli ans = k;
                x -= (k*(k+1))/2 ;
                long double d = sqrtl(  powl( (2*k - 1),2 ) - 8*x );
                lli a1 = ceil(((1-2*k) + d)/(-2.0));
                lli a2 = ceil(((1-2*k) - d)/(-2.0));

                if(a1 >= 0)
                    ans += a1;
                else
                    ans += a2;
                cout<<ans<<"\n";
            }
        }
        t--;
    }
    return 0;
}
