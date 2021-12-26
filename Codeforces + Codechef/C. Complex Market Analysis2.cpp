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

bool is_prime(lli n)
{
    bool flag = 1;
    for(lli i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;

    return flag;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli ans=0;
        lli n,e;
        cin>>n>>e;
        lli a[n+1];
        set<lli> p;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if( is_prime(a[i]) )
                p.insert(i);
        }


        for(auto i:p)
        {
            lli aage = 0;
            lli peeche = 0;
            for(int j=i+e;j<=n;j+=e)
               {
                    if( a[j] != 1)
                        break;
                    else
                        aage++;
               }
            for(int j=i-e;j>=1;j-=e)
            {
                if( a[j] != 1)
                    break;
                else
                    peeche++;
            }

            //cout<<"i = "<<i<<"aage = "<<aage<<" peeche = "<<peeche<<"\n";
            ans += peeche*(aage + 1) + aage;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
