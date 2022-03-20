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
        lli index = 0;
        bool all_single=1;
        for(int i=0; i<s.length()-1; i++)
        {
            lli ss = (s[i+1] - '0') +  (s[i] - '0');

            //cout<<ss<<"\n";

            if(ss >= 10)
            {
                all_single=0;
                index = i;
            }

        }

        if(all_single == 1)
        {
            cout<<((s[0] - '0') + (s[1] - '0'));
            for(int i=2; i<s.length(); i++)
                cout<<s[i];
        }
        else
        {
            for(int i=0; i<index; i++)
                cout<<s[i];
            cout<<s[index] - '0' + s[index+1] - '0';
            for(int i=index+2; i<s.length(); i++)
                cout<<s[i];

        }

        cout<<"\n";
        t--;
    }
    return 0;
}
