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
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0; i<n; i++)
        {
            string x;
            cin>>x;
            v.push_back(x);
        }
        cout<<"aaiya\n";
        string ans = "";
        for(int i=0; i<n; i++)
        {
            cout<<"aaaa\n";
            int o = 0;
            int z = 0;
            for(int j=0; j<n; j++)
            {
                string x = v[j].substr(0,i);
                string a1 = ans + '1';
                string a0 = ans + '0';
                if(a1 == x)
                    o++;
                else if(a0 == x)
                    z++;
            }

            if(o == 0 || z == 0)
            {
                if(o == 0)
                {
                    for(int k=0; k<(n-i-1); k++)
                        ans += '1';
                }
                else
                {
                    for(int k=0; k<(n-i-1); k++)
                        ans += '0';
                }
                goto p;
            }
            else
            {
                if(o <= z)
                    ans += '1';
                else
                    ans += '0';
            }

        cout<<"ans till now = "<<ans<<"\n";
        }
        cout<<ans<<"\n";
        p:
        t--;
    }
    return 0;
}

