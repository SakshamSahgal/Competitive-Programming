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
vector<int> p;
bool prime[32] = {0};
void seive(int n)
{

    for(int i=2; i*i <= n; i++)
    {
        for(int j = i*i; j<=n; j+=i)
            prime[j] = 1;

    }

    for(int i=2; i<=n; i++)
    {
        if(prime[i] == 0)
            p.push_back(i);
    }
}


int main()
{
    GO_FAST
    seive(31);
    int t;
    cin>>t;
    while(t)
    {
        map<int,int> dist;
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        int b[n] = {0};
        int c=1;
        bool found=0;
        for(int i=0; i<p.size(); i++)
        {
            found = 0;
            for(int j=0; j<n; j++)
            {
                if(b[j] == 0)
                {
                    if(a[j]%p[i] == 0)
                    {
                        found = 1;
                        b[j] = c;
                        dist[c]++;
                    }
                }
            }
            if(found == 1)
            c++;

        }

        cout<<dist.size()<<"\n";
        for(auto i:b)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}
