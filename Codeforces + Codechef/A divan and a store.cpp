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
        lli n,l,r,k;
        cin>>n>>l>>r>>k;
        lli a[n];
        vector<lli> x;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] >= l && a[i] <= r)
                x.push_back(a[i]);
        }

        sort(x.begin(),x.end());
        lli sum=0;
        lli c=0;
        for(int i=0;i<x.size();i++)
        {
            if(sum + x[i] > k)
                break;
            else
            {
                sum += x[i];
                c++;
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
