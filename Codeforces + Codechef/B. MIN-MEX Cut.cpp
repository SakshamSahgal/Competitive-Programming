#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
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
        bool zf=0;
        bool of=0;
        for(auto i:s)
        {
            if(i == '0')
                zf=1;
            else if(i == '1')
                of=1;
        }

        int ans;

        if(zf == 1 && of == 1)
            ans = 2;
        else if(zf == 1 && of == 0)
            ans = 1;
        else
            ans = 0;

        if(ans == 0 || ans == 1)
            cout<<ans<<"\n";
        else
        {
            auto ip = std::unique(s.begin(), s.end());

            // Displaying the corrected string
            string xx =  string(s.begin(), ip);

            if(xx.length() == 2)
                cout<<1<<"\n";
            else
            {
                int c=0;
                for(auto i:xx)
                {
                    if(i == '0')
                    {
                        c++;
                        if(c > 2)
                        {
                            cout<<2<<"\n";
                            goto l;
                        }
                    }
                }
                cout<<c<<"\n";
            }
        }




        l:
        t--;
    }
    return 0;
}
