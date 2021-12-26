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
        lli n,s;
        cin>>n>>s;
        lli c=0;

        for(int z=1;z<=n;z++)
        {
            for(int x=1;x<=n;x++)
            {
                lli g = (2*s - z*z - z - 2*x)/2;
                if(g > 0)
                    c += min(n,g);
            }

        }

        cout<<c<<"\n";

        t--;
    }
    return 0;
}
