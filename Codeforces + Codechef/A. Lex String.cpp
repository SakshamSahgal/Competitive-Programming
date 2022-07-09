#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
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
        lli n,m,k;
        cin>>n>>m>>k;
        string a,b;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        queue<char> aq;
        queue<char> bq;

        for(auto i:a)
            aq.push(i);

        for(auto i:b)
            bq.push(i);

        string c="";
        lli ak=0;
        lli bk=0;
        while( !aq.empty() && !bq.empty())
        {
            if(aq.front() < bq.front())
            {
                if(ak < k)
                {
                    c += aq.front();
                    aq.pop();
                    ak++;
                    bk=0;
                }
                else
                {
                    c += bq.front();
                    bq.pop();
                    bk++;
                    ak=0;
                }
            }
            else
            {
                if(bk < k)
                {
                    c += bq.front();
                    bq.pop();
                    bk++;
                    ak=0;
                }
                else
                {
                    c += aq.front();
                    aq.pop();
                    ak++;
                    bk=0;
                }
            }

        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
