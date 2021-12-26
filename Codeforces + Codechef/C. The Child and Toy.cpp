#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    lli v[n+1];

    for(int i=1;i<=n;i++)
        cin>>v[i];

    lli sum=0;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        sum += min( v[x],v[y]);
    }
    cout<<sum<<"\n";

    return 0;
}


