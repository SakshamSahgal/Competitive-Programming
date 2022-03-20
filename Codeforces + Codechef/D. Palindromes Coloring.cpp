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
        string s;
        cin>>s;
        map<lli,lli> f;
        for(int i=0;i<n;i++)
            f[s[i]]++;
        lli p=0;
        lli a=0;
        for(auto i:f)
        {
            p += (i.second)/2;
            a += (i.second)%2;
        }

        //cout<<"("<<p<<" "<<a<<")\n";

        if( p < k )
            cout<<1<<"\n";
        else
        {
            lli mini_size = (p/k)*2;
            lli rem_pair = p - (p/k)*k;

            if( 2*rem_pair +  a >= k)
                cout<<mini_size + 1<<"\n";
            else
                cout<<mini_size<<"\n";
        }

        t--;
    }
    return 0;
}
