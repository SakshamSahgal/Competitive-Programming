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
        lli n,l;
        cin>>n>>l;
        lli a[n];
        map<lli,lli> m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            for(int j=0;j<l;j++)
            {
                if((a[i]>>j)%2)
                    m[j]++;
            }
        }

       // for(int i=0;i<l;i++)
        //    cout<<m[i]<<" ";

       // cout<<"\n";
        vector<lli> x;
        lli ans = 0;
        for(int i=0;i<l;i++)
        {
            if(m[i] > n/2 )
                ans += pow(2,i);

        }
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}
