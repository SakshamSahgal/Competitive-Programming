#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
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

char get_other(char cur)
{
    if(cur == '0')
        return '1';
    else
        return '0';
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        map<char,queue<lli>> m;
        lli n;
        cin>>n;
        string s;
        cin>>s;
        map<lli,vector<lli>> g;
        for(int i=0; i<n; i++)
        {
            char cur = s[i];
            char other = get_other(cur);
            if(!m[other].empty())
            {
                g[m[other].front()].push_back(i);
                m[other].pop();
                m[cur].push(i);
            }
            else
                m[cur].push(i);
        }

        lli b[n] = {0};
        lli c=1;
        for(int i=0;i<n;i++)
        {
            lli cur = i;
            if(b[cur] == 0)
            {
                b[cur] = c;
                while(g[cur].size() != 0)
                {
                    cur = g[cur][0];
                    b[cur] = c;
                }
                c++;
            }
        }

        //display(g);
        //array_printer(b,n);
        cout<<c-1<<"\n";
        for(auto i:b)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

