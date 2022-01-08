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

/*
void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
} */


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
        map<lli,lli> bits;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            for(int j=0; j<32; j++)
                bits[j] += ((a[i]>>j)%2);
        }

        //Map_printer(bits);
        lli ans=0;
        for(auto i:bits)
            if(i.second > 1)
                ans += pow(2,i.first);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
