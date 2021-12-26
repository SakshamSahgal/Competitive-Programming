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
    int n;
    char ad;
    cin>>n>>ad;
    if(ad == 'a')
        for(int i=1;i<=n;i++)cout<<i<<" ";
    else
        for(int i=n;i>=1;i--)cout<<i<<" ";

    return 0;
}
