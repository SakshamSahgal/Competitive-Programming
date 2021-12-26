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
        string s;
        string p;
        cin>>s;
        cin>>p;
        if(s == p)
            cout<<"YES\n";
        else
        {
            bool of=0;
            bool zf=0;
            for(int i=0; i<p.size(); i++)
            {
                if(p[i] == '0')
                    zf=1;
                else
                    of=1;
            }

            if(zf == 1 && of == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        t--;
    }
    return 0;
}
