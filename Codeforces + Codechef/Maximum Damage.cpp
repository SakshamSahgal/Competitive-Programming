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
        lli n;
        cin>>n;
        lli a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
        {
            if(i == 0)
                cout<<((a[i])&(a[i+1]))<<" ";
            else if(i == n-1)
                cout<<((a[i])&(a[i-1]))<<" ";
            else
            {
                lli x = ((a[i])&(a[i-1]));
                lli y = ((a[i])&(a[i+1]));
                cout<<max(x,y)<<" ";
            }

        }

        cout<<"\n";

        t--;
    }
    return 0;
}
