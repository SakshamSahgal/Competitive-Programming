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
        if((s.length())%2 == 0)
        {
            for(int i=0;i<(s.length()/2);i++)
            {
                if(s[i] != s[i + s.length()/2])
                {
                    cout<<"NO\n";
                    goto k;
                }
            }

            cout<<"YES\n";
        }
        else
            cout<<"NO\n";


        k:
        t--;
    }
    return 0;
}
