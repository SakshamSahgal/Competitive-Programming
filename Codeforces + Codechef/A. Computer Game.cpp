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
        lli n;
        cin>>n;
        string s0;
        string s1;
        cin>>s0>>s1;

        for(int i=0;i<n;i++)
        {
            if(s0[i] == '1' && s1[i] == '1')
            {
                cout<<"NO\n";
                goto k;
            }
        }
        cout<<"YES\n";
        k:
        t--;
    }
    return 0;
}
