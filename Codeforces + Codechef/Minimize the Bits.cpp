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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vector<char> a(n);
        vector<char> b(n);
        lli st=0;
        while(st < n && s[st] == '1')
        {
            a[st] = '1';
            b[st] = '0';
            st++;
        }

        if(st != n)
        {
            for(int i=st; i<n; i++)
            {
                if(s[i] == '1')
                {
                    if(i+1 < n && s[i+1] == '1')
                    {
                        lli j=i+1;
                        a[i] = '0';
                        b[i] = '0';
                        while( j < n && s[j] == s[i])
                        {
                            a[j] = '0';
                            b[j] = '0';
                            j++;
                        }
                        j--;
                        a[i-1] = '1';
                        b[j] = '1';
                        i = j;
                    }
                    else
                    {
                        a[i] = '1';
                        b[i] = '0';
                    }
                }
                else
                {
                    a[i] = '0';
                    b[i] = '0';
                }
            }

        }
        for(auto i:a)
            cout<<i;
        cout<<"\n";
        for(auto i:b)
            cout<<i;
        cout<<"\n";

        t--;
    }
    return 0;
}

