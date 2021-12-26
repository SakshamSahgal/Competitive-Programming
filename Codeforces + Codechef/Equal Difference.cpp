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
        lli a[n];
        map<lli,lli> freq;
        lli maxx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
            maxx = max(freq[a[i]],maxx);
        }
        if(n <= 2)
            cout<<0<<"\n";
        else
        cout<<min(n-2,n-maxx)<<"\n";
        t--;
    }
    return 0;
}

