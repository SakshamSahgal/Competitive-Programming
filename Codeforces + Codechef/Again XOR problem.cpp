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

void vector_printer( vector<string> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";
    cout<<"\n------------------------\n";
}


lli no_1_btw(lli *po,lli l,lli r)
{
    if(l == 0)
        return po[r];
    else
        return (po[r] - po[l-1]);
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        string s;
        lli n,k;
        cin>>n>>k;
        cin>>s;
        lli prefix_0[n];
        lli prefix_1[n];
        lli oc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
                oc++;
            prefix_1[i] = oc;
        }
        lli ans=0;
        lli ed = n - (k-1) - 1;
        for(int i=0;i<k;i++,ed++)
            {
                //cout<<"range = "<<i<<" "<<ed<<" NOone = "<<no_1_btw(prefix_1,i,ed)<<"\n";
                if( no_1_btw(prefix_1,i,ed)%2 == 1)
                    ans++;
            }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
