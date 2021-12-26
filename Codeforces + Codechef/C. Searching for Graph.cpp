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
    int t;
    cin>>t;
    while(t)
    {
        lli n,p;
        cin>>n>>p;
        lli x = 2*n + p;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cout<<i<<" "<<j<<"\n";
                x--;
                if(x == 0)
                    goto k;
            }
        }

        k:
        t--;
    }
    return 0;
}
