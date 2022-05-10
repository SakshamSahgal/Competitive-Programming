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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

set<string> ss;


void fun(string s,string t)
{
    string temp;

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'a')
        {
            temp = s;
            temp.replace(i,1,t);
            //cout<<temp<<"\n";
            ss.insert(temp);
            fun(temp,t);
        }
    }
    return;
}

bool is_palindrome(string &s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i] != s[s.length()-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int tt;
    cin>>tt;
    while(tt)
    {
        string s;
        string t;
        cin>>s>>t;

        lli ac=0;
        lli z = s.size();
        if(t.size() == 1 && t[0] == 'a')
            cout<<1<<"\n";
        else
        {

            for(int i=0;i<t.size();i++)
            {
                if(t[i] == 'a')
                    ac++;
            }
            lli h = powl(2,z);
            if(ac > 0)
                cout<<"-1\n";
            else
                cout<<h<<"\n";
        }
        tt--;
    }
    return 0;
}
