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
    int t;
    cin>>t;
    while(t)
    {
        lli noa=0;
        lli nob=0;
        lli n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0; i<n-1; i++)
        {
            if(s[i] == 'a' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'a')
            {
                cout<<i+1<<" "<<i+2<<"\n";
                goto h;
            }
        }
        cout<<"-1 -1\n";
h:
        t--;
    }
    return 0;
}
