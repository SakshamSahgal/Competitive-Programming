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

struct abc
{
    lli l;
    lli r;
    lli d;
};

void cyclic_shift(lli l,lli r,lli a[],lli n)
{
    lli b[n];
    for(int i=0; i<n; i++)
        b[i] = a[i];

    for(int i=l; i<=r; i++)
    {
        if(i == r)
            a[i] = b[l];
        else
            a[i] = b[i+1];
    }
}

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
        lli b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b,b+n);
        vector<abc> ans;
        bool found = 1;
        while(found == 1)
        {
            found = 0;
            for(int i=0; i<n; i++)
            {
                found = 0;
                lli l,r,d;
                lli dest;
                if(a[i] != b[i])
                {
                    for(int j=i+1; j<n; j++)
                    {
                        if(b[j] == a[i])
                        {
                            dest = j;
                            break;
                        }
                    }
                    cyclic_shift(i,dest,a,n);
                    ans.push_back({i+1,dest+1,1});
                    found = 1;
                    break;
                }
            }
        }

        cout<<ans.size()<<"\n";
        for(auto i:ans)
            cout<<i.l<<" "<<i.r<<" "<<i.d<<"\n";

        t--;
    }
    return 0;
}
