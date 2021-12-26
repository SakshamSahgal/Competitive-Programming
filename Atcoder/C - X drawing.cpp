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
    //GO_FAST
    lli n,a,b,p,q,r,s;
    cin>>n>>a>>b;
    cin>>p>>q>>r>>s;
    lli l1,u1,l2,u2;
    l1 = max(1-a,1-b);
    u1 = min(n-a,n-b);

    l2 = max(1-a,b-n);
    u2 = max(n-a,b-1);

    for(lli i=p;i<=q;i++)
    {
        for(lli j=r;j<=s;j++)
        {
            if( ( ( i-a == b-j ) && ( b-j >=l2 && b-j <= u2) )  || (i-a == j-b) && ( j-b >= l1 && j-b <= u1 ) )
                cout<<"#";
            else
                cout<<".";
        }
        cout<<"\n";
    }
    return 0;
}
