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

pair<lli,lli> range(string &s,lli x)
{
    lli n = s.length();
    lli val[n];
    lli a=0;
    pair<lli,lli> p;
    map<lli,vector<lli>> g;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '0')
            a++;
        else
            a--;
        val[i] = a;

        if(g[a - x].size() != 0)
        {
            lli l = g[a-x][0] + 1;
            lli r = i+1;
            p = {l,r};
            return p;
        }
        g[a].push_back(i+1);
    }
    p = {-1,-1};
    return p;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;

        lli noo=0;
        lli noz=0;
        vector<lli> prefix0(n);
        vector<lli> prefix1(n);
        lli a[n];
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                noz++;
            else
                noo++;
        }

        if(n%2 == 1)
            cout<<"NO\n";
        else
        {
            lli req = (max(noo,noz) - min(noo,noz))/2;
            if(req == 0)
            {
                cout<<"YES\n";
                cout<<1<<" "<<n<<"\n";
            }
            else
            {
                if(noz > noo)
                {
                    pair<lli,lli> p = range(s,req);
                    if(p.first == -1)
                        cout<<"NO\n";
                    else
                    {
                        cout<<"YES\n";
                        cout<<p.first<<" "<<p.second<<"\n";
                    }
                }
                else
                {
                    for(int i=0; i<n; i++)
                    {
                        if(s[i] == '0')
                            s[i] = '1';
                        else
                            s[i] = '0';
                    }
                    pair<lli,lli> p = range(s,req);
                    if(p.first == -1)
                        cout<<"NO\n";
                    else
                    {
                        cout<<"YES\n";
                        cout<<p.first<<" "<<p.second<<"\n";
                    }
                }
            }
        }
        t--;
    }



    return 0;
}
