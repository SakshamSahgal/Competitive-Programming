#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n,m;
cin>>n>>m;
set<int> a;
multiset<int> b;

for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.insert(x);
    }

for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        b.insert(x);
    }
lli c=0;
for(auto i = a.begin();i!=a.end();i++)
    {
        auto ptr = lower_bound(b.begin(),b.end(),*i);
        if(ptr == b.end())
            c++;
        else
        {
            b.erase(ptr);
        }
    }
cout<<c<<"\n";
return 0;
}

