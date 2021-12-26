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
    lli n,k;
    cin>>n>>k;
    lli e[n];
    for(int i=0;i<n;i++)
    {
        cin>>e[i];
        if(e[i] > k)
        {
            cout<<"Difficult Loss\n";
            goto x;
        }
    }
    cout<<"Easy Win!\n";
    x:
    return 0;
}
