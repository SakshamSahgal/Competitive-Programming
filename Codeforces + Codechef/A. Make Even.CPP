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
        bool found=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
            cout<<-1<<"\n";
        else
        {
            if(s[s.length()-1] == '2' || s[s.length()-1] == '4' || s[s.length()-1] == '6' || s[s.length()-1] == '8')
                cout<<0<<"\n";
            else if(s[0] == '2' || s[0] == '4' || s[0] == '6' || s[0] == '8')
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }

        t--;
    }
    return 0;
}
