#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

bool is_palindrome(string &s)
{
    for(int i=0; i<s.length()/2; i++)
    {
        if(s[i] != s[s.length()-i-1])
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
        lli n;
        cin>>n;
        lli noo=0;
        lli noz=0;
        lli noo_sz=0;
        vector<string> v;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;

            if(s.length()%2)
                noo_sz++;

            for(int i=0; i<s.length(); i++)
            {
                if(s[i] == '1')
                    noo++;
                else
                    noz++;
            }
            v.push_back(s);
        }

        if(noz%2 && noo%2)
        {
            if(noo_sz >= 2)
                cout<<n<<"\n";
            else
                cout<<n-1<<"\n";
        }
        else
            cout<<n<<"\n";

        t--;
    }
    return 0;
}

