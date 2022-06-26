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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(s.begin(),s.end());

        bool all_same = 1;

        for (int i = 1; i < k; i++)
        {
            if (s[i] != s[0])
            {
                all_same = 0;
                break;
            }
        }

        if (all_same)
        {
            bool all_aage_same = 1;
            string ans = "";
            
            for (int i = k + 1; i < n; i++)
            {
                if (s[i] != s[k])
                {
                    all_aage_same = 0;
                    break;
                }
            }

            if(all_aage_same)
            {
                for(int i=k-1;i<n;i+=k)
                    ans += s[i];
                
                if((n%k))
                 ans += s[n-1];
            }
            else
            {
                ans = s[0];
                for(int i=k;i<n;i++)
                    ans += s[i];
            }
            
            cout << ans << "\n";
        }
        else
            cout << s[k - 1] << "\n";
        t--;
    }
    return 0;
}