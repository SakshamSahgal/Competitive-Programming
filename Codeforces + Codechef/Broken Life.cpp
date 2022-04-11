#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        string s,a;
        cin>>s>>a;
        queue<char> q;
        lli b[s.length()];
        for(int i=0;i<a.length();i++)
            q.push(a[i]);

        lli c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == q.front())
            {
                b[i] = ++c;
                q.pop();
            }
            else
                b[i] = c;

            if(q.empty())
            {
                cout<<"-1\n";
                goto l;
            }
        }

        //array_printer(b,n);

        for(int i=0;i<n;i++)
        {
            if(s[i] == '?')
            {
                if(a[b[i]] == 'a')
                    s[i] = 'b';
                else if(a[b[i]] == 'b')
                    s[i] = 'c';
                else if(a[b[i]] == 'c')
                    s[i] = 'd';
                else if(a[b[i]] == 'd')
                    s[i] = 'e';
                else
                    s[i] = 'a';
            }
        }
        cout<<s<<"\n";
        l:
        t--;
    }
    return 0;
}

