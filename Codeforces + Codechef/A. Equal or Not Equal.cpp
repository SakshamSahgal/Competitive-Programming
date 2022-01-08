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
        lli non=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'N')
                non++;
        }

        if(non == 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";


        t--;
    }
    return 0;
}
