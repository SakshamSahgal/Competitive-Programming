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

char opp(char x)
{
    if(x == '(')
        return ')';
    else
        return '(';
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        for(int i=0; i<(2*n); i++)
        {
            if(i<n)
                s += '(';
            else
                s += ')';
        }

        cout<<s<<"\n";
        int x = n-1;
        int y = n;
        for(int i=1; i<n; i++,x--,y++)
        {
            for(int j=0;j<(2*n);j++)
            {
                if(j == x || j == y)
                    cout<<opp(s[j]);
                else
                    cout<<s[j];
            }
            cout<<"\n";
        }

        t--;
    }
    return 0;
}
