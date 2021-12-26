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
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        lli n = s.length();
        char x[n];
        for(int i=0;i<n;i++)
            x[i] = s[i];

        n = unique(x, x + n) - x;

        if(x[0] == '0')
            cout<<n<<"\n";
        else
            cout<<n-1<<"\n";

        t--;
    }
    return 0;
}
