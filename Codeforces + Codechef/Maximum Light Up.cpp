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
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli p,a,b,c,x,y;
        cin>>p>>a>>b>>c>>x>>y;
        lli nc;
        lli maxx = INT_MIN;
        lli u = b + a*x;
        lli v = c + a*y;
        for(lli na=0;na<=(p/u);na++)
        {
            nc = ( p - na*u )/v;
            maxx = max(maxx,(nc+na));
        }

        cout<<maxx<<"\n";
        t--;
    }
    return 0;
}
