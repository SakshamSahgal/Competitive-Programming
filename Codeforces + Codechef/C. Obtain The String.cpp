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

bool is_available(queue<char> s,queue<char> sub)
{
    while(!sub.empty())
    {
        while( (s.front()) != (sub.front()) )
        {
            if(!s.empty())
                s.pop();
            else
                return 0;
        }
        sub.pop();
        s.pop();
    }
    return 1;
}


int main()
{
    GO_FAST
    int tt;
    cin>>tt;
    while(tt)
    {
        string s;
        string t;
        cin>>s>>t;
        map<char,vector<lli>> fs;
        set<char> dt;
        lli c=0;
        queue<char> qt;

        for(int i=0;i<s.length();i++)
            fs[s[i]].push_back(i);

        for(int i=0;i<t.length();i++)
        {
            dt.insert(t[i]);
            qt.push(t[i]);
        }

        for(auto i:dt)
        {
            if(!fs[i].size())
            {
                cout<<"-1\n";
                goto l;
            }
        }

        while(!qt.empty())
        {
             c++;
             lli bb = 0;

             while(1)
             {
                 //cout<<"bb now = "<<bb<<"\n";
                 char cur = qt.front();
                 auto ptr = lower_bound(fs[cur].begin(),fs[cur].end(),bb);
                 if(ptr != fs[cur].end())
                 {
                    qt.pop();
                    bb = *ptr + 1;
                    if(qt.empty())
                        break;
                 }
                 else
                    break;
             }


        }
        cout<<c<<"\n";
        l:
        tt--;
    }
    return 0;
}

