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
    string s1,s2;
    cin>>s1>>s2;
    if(s1 == "#." && s2 == ".#" || s2 == "#." && s1 == ".#")
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}
