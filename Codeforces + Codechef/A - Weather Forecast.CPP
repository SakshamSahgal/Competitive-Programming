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
    cin>>n;
    string s;
    cin>>s;

    if(s[n-1] == 'o')
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
