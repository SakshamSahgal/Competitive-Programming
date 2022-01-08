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
        lli n,k;
        cin>>n>>k;
        lli a[n+1];
        lli ans = 0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ans += a[i];
        }


        sort(a+1,a+n+1);

        for(int i=n,j=n-k,l=1;l<=k;i--,j--,l++)
        {
            //cout<<"("<<i<<" "<<j<<")\n";
            ans += (a[j]/a[i]);
            ans -= a[j];
            ans -= a[i];
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
