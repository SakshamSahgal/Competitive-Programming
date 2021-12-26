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
    string t;

    for(int i=1; i<=10; i++)
        t+= "oxx";

    string s;
    cin>>s;

    lli f = t.find(s);

    if(f >= 0 && f< t.length())
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
