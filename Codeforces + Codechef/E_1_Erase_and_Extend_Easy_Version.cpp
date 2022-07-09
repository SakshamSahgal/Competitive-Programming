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



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    lli st=-1;
    for(int i=1; i<s.length(); i++)
    {
        if(s[0] < s[i])
        {
            st = i;
            break;
        }
        else if(s[0] == s[i])
        {
            lli l1 = i;
            lli l2 = s.length() - i;
            if(l1 < l2)
            {
                string s1 = s.substr(0,l1);
                string s2 = s.substr(i,l1);
                if(s1 == s2 && s[i + l1] > s[0] || (s1 < s2))
                {
                    st = i;
                    break;
                }
            }
            else if(l1 > l2)
            {
                string s1 = s.substr(0,l2);
                string s2 = s.substr(i,l2);
                if(s1 <= s2)
                {
                    st = i;
                    break;
                }
            }
            else
            {
                string s1 = s.substr(0,l1);
                string s2 = s.substr(i,l2);
                if(s1 < s2)
                {
                    st = i;
                    break;
                }
            }
        }
    }
    if(st != -1)
        s.erase(s.begin()+st,s.end());

    while(s.length() < k)
        s += s;

    while(s.length() > k)
        s.erase(s.begin() + s.length() - 1,s.end());

    cout<<s<<"\n";

    return 0;
}
