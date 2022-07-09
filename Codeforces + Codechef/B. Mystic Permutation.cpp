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

//remember to use endl instead of \n for interactive problems.

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
        lli a[n];
        set<lli> rem;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            rem.insert(a[i]);
        }
        if(n == 1)
            cout<<"-1\n";
        else
        {
            vector<lli> ans;
            bool fail=0;
            for(int i=0; i<n; i++)
            {
                auto ptr = rem.begin();
                if( (*ptr) != a[i])
                {
                    ans.push_back((*ptr));
                    rem.erase(ptr);
                }
                else
                {
                    ptr++;
                    if(ptr == rem.end())
                    {
                        fail=1;
                        ptr--;
                        ans.push_back((*ptr));
                        rem.erase(ptr);
                    }
                    else
                    {
                        ans.push_back((*ptr));
                        rem.erase(ptr);
                    }
                }
            }
            if(fail)
                swap(ans[n-1],ans[n-2]);
            for(auto i:ans)
                cout<<i<<" ";
            cout<<"\n";

        }

        t--;
    }
    return 0;
}
