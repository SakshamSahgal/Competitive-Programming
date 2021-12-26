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

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

void cyclic_shift(lli l,lli r,lli d,lli a[],lli n)
{
    lli b[n+1];
    for(int i=l; i<=r; i++)
        b[i] = a[i];

    for(int i=l; i<=r; i++)
    {
        lli dest;
        if( i - d < l)
            dest =  r - (l - (i - d)) + 1;
        else
            dest = i-d;
        a[dest] = b[i];
    }
}
int main()
{
    GO_FAST
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n+1];
        lli b[n+1];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        vector<abc> ans;
       // cyclic_shift(2,4,1,a,n);
        //array_printer(a,n);

        for(int i=1;i<=n;i++)
        {
            if(b[i] != a[i])
            {
                for(int j = i+1;j<=n;j++)
                {
                    if(b[i] == a[j])
                    {
                        cyclic_shift(i,j,j-i,a,n);
                        //array_printer(a,n);
                        ans.push_back({i,j,j-i});
                        break;
                    }
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
