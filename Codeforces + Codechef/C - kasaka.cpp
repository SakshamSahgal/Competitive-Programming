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

bool is_palindrome(string &s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i] != s[s.length()-i-1])
            return 0;
    }
    return 1;
}


lli LongestPalindromicPrefix(string str)
{

    string temp = str + '?';
    reverse(str.begin(), str.end());
    temp += str;
    int n = temp.length();
    int lps[n];

    fill(lps, lps + n, 0);
    for (int i = 1; i < n; i++) {

        int len = lps[i - 1];
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
        if (temp[i] == temp[len]) {
            len++;
        }
        lps[i] = len;
    }
    string ss = temp.substr(0, lps[n - 1]);
    //cout<<ss<<"\n";
    return (ss.length());
}

int main()
{
    //GO_FAST
    string s;
    cin>>s;
    lli ed = LongestPalindromicPrefix(s);
    bool fail=0;
    for(int i = ed;i<s.length();i++)
    {
        if(s[i] != 'a')
        {
            fail = 1;
            break;
        }
    }

    if(fail)
        cout<<"No\n";
    else
        cout<<"Yes\n";

    return 0;
}

