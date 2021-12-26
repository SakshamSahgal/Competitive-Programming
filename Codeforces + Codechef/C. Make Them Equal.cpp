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
        lli n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        bool found=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] != c)
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
            cout<<0<<"\n";
        else
        {

            lli ans=0;
           for(int i=n/2+1;i<=n;i++)
            {
                if(s[i-1] == c)
                {
                    ans = i;
                    break;
                }
            }

            if(ans != 0)
            {
                cout<<1<<"\n";
                cout<<ans<<"\n";
            }
            else
            {
                cout<<2<<"\n";
                cout<<n<<" "<<n-1<<"\n";
            }
        }

        t--;
    }
    return 0;
}
