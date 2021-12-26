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

lli dur(lli st,lli ed)
{
    if(ed >= st)
        return (ed-st+1);
    else
        return (24-st + ed + 1);
}

int main()
{
    //GO_FAST
    lli s,t,x;
    cin>>s>>t>>x;
    for(int i=s,j=0;j<dur(s,t);i++,j++)
        {
            i = i%24;
            cout<<i<<"\n";
        }
    return 0;
}
