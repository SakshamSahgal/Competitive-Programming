#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        lli sum=0;
        lli mini = inf;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            mini = min(a[i],mini);
            sum += a[i];
            f[a[i]]++;
        }
        lli noo = 0;

        if(n == 1)
            cout<<"YES\n";
        else
        {
            if(sum < 2)
                cout<<"NO\n";
            else
            {
                queue<lli> q;
                q.push(sum);

                while(!q.empty())
                {
                    lli top = q.front();
                    if(top < mini)
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                    else
                    {
                        q.pop();
                        if(f[top] != 0)
                            f[top]--;
                        else
                        {
                            if(top >= 2)
                            {
                                noo++;
                                if(noo > n-1)
                                {
                                    cout<<"NO\n";
                                    goto l;
                                }
                                q.push(top/2);
                                q.push(top - (top/2));
                            }
                            else
                            {
                                cout<<"NO\n";
                                goto l;
                            }
                        }
                    }
                }

                for(auto i:f)
                {
                    if(i.second != 0)
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }
                cout<<"YES\n";
            }
        }
l:
        t--;
    }
    return 0;
}

