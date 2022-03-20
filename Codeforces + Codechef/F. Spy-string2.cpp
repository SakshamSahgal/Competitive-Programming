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

vector<string> all_possible(string s)
{
    vector<string> x;
    x.push_back(s);
    for(int i=0;i<s.length();i++)
    {
        char orig = s[i];
        for(char j='a';j<='z';j++)
        {
            if(j != orig)
                {
                    s[i] = j;
                    x.push_back(s);
                }
        }
        s[i] = orig;
    }
    return x;
}

void vector_printer( vector<string> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";
    cout<<"\n------------------------\n";
}

bool is_possible(string s,vector<string> &v)
{
    for(int i=0;i<v.size();i++)
    {
        lli c=0;
        for(int j=0;j<v[i].size();j++)
        {
            if(s[j] != v[i][j])
                c++;
        }

        if( c > 1)
            return 0;
    }

    return 1;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        vector<string> v(n);

        for(int i=0;i<n;i++)
            cin>>v[i];

        for(int i=0;i<n;i++)
        {
            vector<string> x = all_possible(v[i]);
            for(auto j:x)
            {
                //cout<<"trying - "<<j<<"\n";
                if(is_possible(j,v))
                {
                    cout<<j<<"\n";
                    goto k;
                }
            }
        }
        cout<<"-1\n";
        k:
        t--;
    }
    return 0;
}

