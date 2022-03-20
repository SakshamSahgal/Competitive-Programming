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
    //GO_FAST

    lli l,r;
    cin>>l>>r;

    queue<pair<lli,lli>> q;
    q.push({l,r});
    if(__gcd(l,r) == 1)
        cout<<r-l<<"\n";
    else
    {
        while(1)
        {
            queue<pair<lli,lli>> temp;

            while(!q.empty())
            {
                lli x = q.front().first;
                lli y = q.front().second;
                temp.push({x+1,y});
                temp.push({x,y-1});
                q.pop();
                if(__gcd(x+1,y) == 1 || __gcd(x,y-1) == 1)
                {
                    cout<<y-x-1<<"\n";
                    goto l;
                }

            }

            q = temp;

        }
    }

l:
    return 0;
}
