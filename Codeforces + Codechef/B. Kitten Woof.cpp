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
    string ans[6] = {"050","080","170","020","200","110"};
    int n;
    cin>>n;
    if(n < 3)
        cout<<"-1\n";
    else if(n == 3)
        cout<<"210\n";
    else
    {
        cout<<1;
        for(int i=1; i<=(n-4); i++)
            cout<<"0";
        cout<<ans[(n-4)%6]<<"\n";
    }
    return 0;
}
