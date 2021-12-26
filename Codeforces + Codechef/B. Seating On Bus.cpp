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
    lli n,m;
    cin>>n>>m;
    lli x[n][4];
    lli cc = 1;
    for(int i=n-1; i>=0; i--)
    {
        x[i][0] = cc++;
        x[i][3] = cc++;
    }

    for(int i=n-1; i>=0; i--)
    {
        x[i][1] = cc++;
        x[i][2] = cc++;
    }

    for(int i=n-1; i>=0; i--)
    {
        if(x[i][1] <= m)
            cout<<x[i][1]<<" ";
        if(x[i][0] <= m)
            cout<<x[i][0]<<" ";
        if(x[i][2] <= m)
            cout<<x[i][2]<<" ";
        if(x[i][3] <= m)
            cout<<x[i][3]<<" ";
    }

    return 0;
}
