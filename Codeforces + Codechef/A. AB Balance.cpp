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
        lli ab=0;
        string s;
        cin>>s;
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i] == 'a' && s[i+1] == 'b')
                ab++;
            if(s[i] == 'b' && s[i+1] == 'a')
                ab--;
        }

        if(ab == 0)
            cout<<s<<"\n";
        else if( ab > 0)
        {
            for(int i=0; i<s.length()-1; i++)
                cout<<s[i];
            cout<<"a\n";
        }
        else
        {
            for(int i=0; i<s.length()-1; i++)
                cout<<s[i];
            cout<<"b\n";
        }


        t--;
    }
    return 0;
}
