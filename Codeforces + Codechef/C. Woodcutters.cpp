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
    lli n;
    cin>>n;
    lli a[n];
    lli h[n];
    for(int i=0; i<n; i++)
        cin>>a[i]>>h[i];

    lli first_free = 0;
    lli ans=0;
    for(lli i=0;i<n;i++)
    {
        if(i == 0)
        {
            first_free = a[i] + 1;
            ans++;
        }
        else if( i == n-1 )
        {
            first_free = a[i] + h[i] + 1;
            ans++;
        }
        else
        {
            if( first_free <= (a[i] - h[i]) ) //left
            {
                ans++;
                first_free = a[i] + 1;
            }
            else if(a[i] + h[i] < a[i+1]) //right
            {
                ans++;
                first_free = a[i] + h[i] + 1;
            }
            else
                first_free = a[i] + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
