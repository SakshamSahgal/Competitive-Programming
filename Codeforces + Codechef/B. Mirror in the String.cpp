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
        cin>>s;
        string x,y;
        x += s[0];
        for(int i=1;i<s.length();i++)
        {
            if(i == 1)
            {
                if(s[i-1] > s[i])
                    x += s[i];
                else
                    break;
            }
            else
            {
                if(s[i-1] >= s[i])
                    x += s[i];
                else
                    break;
            }
        }
        y = x;
        for(int i=x.length()-1;i>=0;i--)
            y += x[i];

        cout<<y<<"\n";
        t--;
    }
    return 0;
}
