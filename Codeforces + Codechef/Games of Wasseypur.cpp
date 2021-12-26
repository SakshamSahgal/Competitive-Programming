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
lli maxx = 1e5 + 1;
int main()
{
    GO_FAST
    int t;
    cin>>t;
    lli dy[maxx];
    dy[1]=1;
    dy[2]=0;
    for(int i=3; i<maxx; i++)
    {
        lli x = (min(dy[i-1],dy[i-2]));
        dy[i] = x^1;
    }

    while(t)
    {
        lli c=0;
        lli n;
        cin>>n;
        string s;
        cin>>s;
        char cc = '2';
        for(int i=0; i<s.length(); i++)
        {
            if( s[i] != cc)
            {
                cc = s[i];
                c++;
            }
        }
        if(dy[c])
            cout<<"SAHID\n";
        else
            cout<<"RAMADHIR\n";

        t--;
    }
    return 0;
}
