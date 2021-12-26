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
        lli n,m;
        cin>>n>>m;
        bool root[n+1] = {0};
        for(lli i=0; i<m; i++)
        {
            lli a,b,c;
            cin>>a>>b>>c;
            root[b] = 1;
        }
        lli rr=-1;
        for(lli i=1; i<=n; i++)
        {
            if(root[i] == 0)
            {
                rr = i;
                break;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(i != rr)
                cout<<rr<<" "<<i<<"\n";
        }

        t--;
    }
    return 0;
}
