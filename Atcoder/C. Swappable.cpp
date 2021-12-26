#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
lli n;
cin>>n;
map<lli,lli>freq;
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    freq[x]++;
}

lli sum= ((n-1)*n)/2;

for(auto i = freq.begin();i!=freq.end();i++)
  sum -= ((((i->second)-1)*(i->second))/2);

cout<<sum<<"\n";
return 0;
}
