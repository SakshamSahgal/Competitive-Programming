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
        map<lli,lli> f;
        lli a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            f[abs(a[i])]++;
        }
        lli c=0;
        for(auto i:f)
        {
            if(i.first == 0)
                c++;
            else
                c += min((i.second),(lli)2);
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
