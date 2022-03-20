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
        lli n,s,k;
        cin>>n>>s>>k;
        map<lli,lli> closed;
        for(int i=0;i<k;i++)
        {
            lli x;
            cin>>x;
            closed[x] = 1;
        }

        for(int j=0;;j++)
        {
            if( ( s-j >= 1 && closed[s-j] == 0 ) || ( closed[s+j] == 0 && s+j <= n) )
            {
                cout<<j<<"\n";
                break;
            }
        }
        t--;
    }
    return 0;
}
