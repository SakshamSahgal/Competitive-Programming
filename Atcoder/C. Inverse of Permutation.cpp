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
    GO_FAST
    int n;
    cin>>n;
    int p[n+1];
    int q[n+1];

    for(int i=1;i<=n;i++)
    {
      cin>>p[i];
      q[p[i]] = i;
    }


    for(int i=1;i<=n;i++)
      cout<<q[i]<<" ";

    return 0;
}
