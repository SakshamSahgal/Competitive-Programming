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

        lli n;
        cin>>n;
        lli a[n];
        lli sum=0;
        lli maxx = INT_MIN;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
            maxx = max(a[i],maxx);
        }

        if(sum%2 == 0 && ( sum - maxx ) >= maxx )
            cout<<"YES\n";
        else
            cout<<"NO\n";

    return 0;
}
