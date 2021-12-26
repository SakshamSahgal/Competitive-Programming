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
        vector<lli> odd;
        vector<lli> even;

        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }

        if(odd.size() >= 1 && even.size() >= 1)
        {
            for(auto i:odd)
                cout<<i<<" ";
            for(auto i:even)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
            cout<<"-1\n";

        t--;
    }
    return 0;
}
