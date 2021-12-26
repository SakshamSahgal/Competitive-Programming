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
    lli t;
    cin>>t;
    while(t)
    {
        lli n,m,x,y;
        cin>>n>>m>>x>>y;
        if( 2*x <= y)
            cout<<(n-1)*x + (m-1)*x<<"\n";
        else
        {
            if(n > 1 && m > 1)
            {
                if( y <= x)
                    cout<<((min(n,m) - 1)*y) + ( ((max(n,m) - min(n,m))) - (((max(n,m) - min(n,m)))%2) )*y +  (((max(n,m) - min(n,m)))%2)*x<<"\n";
                else
                    cout<<((min(n,m) - 1)*y) + ((max(n,m) - min(n,m))*x)<<"\n";
            }
            else
                cout<<(n-1)*x + (m-1)*x<<"\n";
        }
        t--;
    }
    return 0;
}
