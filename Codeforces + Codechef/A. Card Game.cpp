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
        lli n,k1,k2;
        cin>>n>>k1>>k2;
        lli maxx1 = INT_MIN;
        lli maxx2 = INT_MIN;
        for(int i=0;i<k1;i++)
        {
            lli x;
            cin>>x;
            maxx1 = max(x,maxx1);
        }

        for(int i=0;i<k2;i++)
        {
            lli x;
            cin>>x;
            maxx2 = max(x,maxx2);
        }

        if(maxx1 > maxx2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }
    return 0;
}
