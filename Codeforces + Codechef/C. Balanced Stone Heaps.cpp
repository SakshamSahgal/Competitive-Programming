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

lli binary_s(mini,a,b,c)
{
    lli low = 0;
    lli high = c/d;
    lli d = 0;
    while(low <= high)
    {
        lli mid = (low + high) / 2;

        if( min( a + 2*mid,min(b + mid,c-3*mid) )  mini )
        {

        }

    }
}

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
        lli mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mini = min(a[i],mini);
        }


        for(int i=2;i<n;i++)
        {
            lli best_d = binary_s(mini,a[i-2],a[i-1],a[i]);
        }
        t--;
    }
    return 0;
}
