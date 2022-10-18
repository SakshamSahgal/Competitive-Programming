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
        lli n,x,y;
        cin>>n>>x>>y;
        lli mn = min(x,y);
        lli mx = max(x,y);
        vector<lli> ans;
        if(mn == 0 && mx != 0)
        {
            if(n == 2)
            {
                if(mx == 1)
                    cout<<1<<"\n";
                else
                    cout<<"-1\n";
            }
            else
            {
                if(n%2)
                {
                    if(mx == n-1 || (mx >= 1 && mx <= n/2) )
                    {
                        if(mx ==  n-1)
                        {
                            for(int i=1; i<=mx; i++)
                                cout<<1<<" ";
                            cout<<"\n";
                        }
                        else
                        {
                            for(lli i=0; i<mx; i++)
                                ans.push_back(1);
                            for(lli i=0; i<mx; i++)
                                ans.push_back(mx+2);
                            lli lst = mx+2;
                            while(ans.size() < n-1)
                            {
                                lst += mx;
                                for(int i=0; i<mx; i++)
                                    ans.push_back(lst);
                            }
                            for(auto i:ans)
                                cout<<i<<" ";
                            cout<<"\n";
                        }
                    }
                    else
                        cout<<"-1\n";
                }
                else
                {
                    if(mx == 1 || mx == n-1)
                    {
                        if(mx ==  n-1)
                        {
                            for(int i=1; i<=mx; i++)
                                cout<<1<<" ";
                            cout<<"\n";
                        }
                        else
                        {
                            for(int i=1;i<=n;i++)
                                if(i != 2)
                                    cout<<i<<" ";
                            cout<<"\n";
                        }
                    }
                    else
                        cout<<"-1\n";
                }
            }
        }
        else
            cout<<"-1\n";
        t--;
    }
    return 0;
}

