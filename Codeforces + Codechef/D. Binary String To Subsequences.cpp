#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

char get_cur(map<char,set<lli>> &g)
{
    if( ( g['0'].size() != 0 ) && ( g['1'].size() != 0 ) )
    {
        if( (*(g['0'].begin())) < (*(g['1'].begin())) )
            return '0';
        else
            return '1';
    }
    else if( g['0'].size() == 0 && ( g['1'].size() != 0 ) )
        return '1';
    else if( g['0'].size() != 0 && ( g['1'].size() == 0 ) )
        return '0';
    else
        return '-';
}

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
        lli n;
        cin>>n;
        string s;
        cin>>s;
        map<char,set<lli>> g;
        for(int i=0; i<n; i++)
            g[s[i]].insert(i);

        lli c=1;
        lli b[n] = {0};

        char cur = get_cur(g);
        char other = get_other(cur);

        while(1)
        {
            cur = get_cur(g);
            other = get_other(cur);
            if(cur =='-')
                break;
            lli cur_index = (*g[cur].begin());
            g[cur].erase(g[cur].find(cur_index));
            b[cur_index] = c;
            //cout<<"Cur index = "<<cur_index<<"\n";
            while(1)
            {
                auto ptr = g[other].lower_bound(cur_index);
                if(ptr == g[other].end())
                {
                    c++;
                    break;
                }
                else
                {
                    cur_index = *ptr;
                    b[cur_index] = c;
                    //cout<<"Cur index = "<<cur_index<<"\n";
                    cur = other;
                    other = get_other(cur);
                    g[cur].erase(g[cur].find(cur_index));
                }
            }
            //line_printer(20);
        }

        //array_printer(b,n);
        cout<<c-1<<"\n";
        for(auto i:b)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

