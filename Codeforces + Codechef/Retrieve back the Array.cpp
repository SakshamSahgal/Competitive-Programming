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
        lli n,x;
        cin>>n>>x;

        lli y=0;
        for(int i=0; i<n-1; i++)
        {
            cout<<i<<" ";
            y = (y^i);
        }
        cout<<(y^x)<<"\n";

        t--;
    }
    return 0;
}
