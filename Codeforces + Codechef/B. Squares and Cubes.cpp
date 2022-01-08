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
        lli n;
        cin>>n;

        lli nos = 0;
        lli noc = 0;
        set<lli> x;
        for(int i=1;i*i<=n;i++)
            x.insert((i*i));

        for(int i=1;i*i*i<=n;i++)
            x.insert((i*i*i));

        cout<<x.size()<<"\n";
        t--;
    }
    return 0;
}
