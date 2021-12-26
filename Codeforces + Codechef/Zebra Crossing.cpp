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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli lstone=0;
        lli lstzero=0;
        lli a[n];

        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
                lstone = i;
            else
                lstzero = i;
            a[i] = (s[i] - 48);
        }

        n = unique(a, a + n) - a;
        //cout<<n<<"\n";
        if(n >= (k+1))
        {
           if(a[0] == 0)
           {
               if(k%2 == 1)
                cout<<lstone+1<<"\n";
               else
                cout<<lstzero+1<<"\n";
           }
           else
           {
            if(k%2 == 1)
                cout<<lstzero+1<<"\n";
               else
                cout<<lstone+1<<"\n";
           }

        }
        else
            cout<<"-1\n";
        t--;
    }
    return 0;
}
