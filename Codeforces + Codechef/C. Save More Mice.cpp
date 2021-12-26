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
        lli n,k;
        cin>>n>>k;
        map<lli,lli> a;
        lli saved=k;
        for(lli i=1,x; i<=k; i++)
        {
            cin>>x;
            a[x]++;
        }

       // for(auto i:a)
           // cout<<i.first<<" "<<i.second<<"\n";

        lli sum=0;
        lli x=0;


        for(auto i = a.begin(); i!=a.end(); i++)
        {
            x+= i->second;

            if(i->first != a.rbegin()->first)
            {
                auto j = i;
                j++;
                lli next = j->first;
                sum += ( next - i->first )*x;
            }
            else
                sum += x*(n-i->first);

            // cout<<sum<<"\n";
        }
        //cout<<sum<<"\n";
        for(auto i:a)
        {
            if( sum <= (n-1) )
            {
                cout<<saved<<"\n";
                goto l;
            }
            else
            {
                for(lli j=1; j<=i.second; j++)
                {
                    sum -= (n-i.first);
                    saved--;

                    if( sum <= (n-1) )
                    {
                        cout<<saved<<"\n";
                        goto l;
                    }

                }
            }

        }
        cout<<0<<"\n";
l:
        t--;
    }
    return 0;
}
