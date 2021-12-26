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
    lli n,t,k,d;
    cin>>n>>t>>k>>d;
    lli t1 = ceil(((double)n)/k)*t;

    lli cc = 0;
    lli tt;
    for(tt=0;; tt++)
    {

        if(tt%t == 0 && tt != 0)
            cc+=k;
        if( (tt-d) >= 0)
            if((tt-d)%t == 0 && (tt-d) != 0)
                cc+=k;
        //cout<<"cakes at t = "<<tt<<" = "<<cc<<"\n";
        if(cc >= n)
            break;
    }
    //cout<<"t1 = "<<t1<<" tt == "<<tt<<"\n";
    if(t1 > tt)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
