#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    string s;
    cin>>s;
    lli v=0;
    lli n = s.length();
    map<lli,lli> last;
    vector<lli> h(26,-1);
    last[0] = -1;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(')
        {
            v++;
            last[v] =  i;
        }
        else if(s[i] == ')')
        {
            v--;
            lli st = last[v]+1;
            lli ed = i;
            //cout<<"i = "<<i<<" st = "<<st<<" ed = "<<ed<<"\n";
            for(int j=0;j<26;j++)
            {
                if(h[j] >= st && h[j] <= ed)
                    h[j] = -1;
            }
            last[v] = i;
        }
        else
        {
            if( h[(s[i] - 'a')] == -1) //not dala
                h[(s[i] - 'a')] = i;
            else
            {
                cout<<"No\n";
                goto l;
            }
            last[v] = i;
        }
    }
    cout<<"Yes\n";
    l:
    return 0;
}

