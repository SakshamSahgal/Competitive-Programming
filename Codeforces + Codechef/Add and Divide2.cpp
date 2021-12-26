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
vector<pair<int,int>> prime_factorisation(int n)
{
    vector<pair<int,int>> p;

    if(n == 1)
        p.push_back({1,1});
    else
    {
        for(int i=2; i*i<=n; i++)
        {
            lli power = 0;
            while( n%i == 0)
            {
                power++;
                n/=i;
            }

            if(power != 0)
                p.push_back({i,power});

            if(n == 1)
                break;
        }

        if(n != 1)
            p.push_back({n,1});
    }
    return p;

}

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int a,b;
        cin>>a>>b;
        vector<pair<int,int>> ap = prime_factorisation(a);
        for(auto i:ap)
        {
            if(b%i.first != 0)
            {
                cout<<"NO\n";
                goto k;
            }
        }

        cout<<"YES\n";
        k:
        t--;
    }
    return 0;
}
